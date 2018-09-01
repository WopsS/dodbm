#include <dodbm/exception.hpp>
#include <dodbm/sql_generator.hpp>

dodbm::command dodbm::sql_generator::generate(operation& operation, const sql_generator_helper& helper)
{
    using type = operation::type;

    switch (operation.get_type())
    {
        case type::alter_database:
        {
            auto& instance = *static_cast<operations::alter_database*>(&operation);
            return generate(instance, helper);
        }
        case type::drop_schema:
        {
            auto& instance = *static_cast<operations::drop_schema*>(&operation);
            return generate(instance, helper);
        }
        case type::ensure_schema:
        {
            auto& instance = *static_cast<operations::ensure_schema*>(&operation);
            return generate(instance, helper);
        }
        case type::alter_table:
        {
            auto& instance = *static_cast<operations::alter_table*>(&operation);
            return generate(instance, helper);
        }
        case type::create_table:
        {
            auto& instance = *static_cast<operations::create_table*>(&operation);
            return generate(instance, helper);
        }
        case type::drop_table:
        {
            auto& instance = *static_cast<operations::drop_table*>(&operation);
            return generate(instance, helper);
        }
        case type::rename_table:
        {
            auto& instance = *static_cast<operations::rename_table*>(&operation);
            return generate(instance, helper);
        }
        case type::add_column:
        {
            auto& instance = *static_cast<operations::add_column*>(&operation);
            return generate(instance, helper);
        }
        case type::alter_column:
        {
            auto& instance = *static_cast<operations::alter_column*>(&operation);
            return generate(instance, helper);
        }
        case type::drop_column:
        {
            auto& instance = *static_cast<operations::drop_column*>(&operation);
            return generate(instance, helper);
        }
        case type::rename_column:
        {
            auto& instance = *static_cast<operations::rename_column*>(&operation);
            return generate(instance, helper);
        }
        case type::add_primary_key:
        {
            auto& instance = *static_cast<operations::add_primary_key*>(&operation);
            return generate(instance, helper);
        }
        case type::drop_primary_key:
        {
            auto& instance = *static_cast<operations::drop_primary_key*>(&operation);
            return generate(instance, helper);
        }
        case type::add_foreign_key:
        {
            auto& instance = *static_cast<operations::add_foreign_key*>(&operation);
            return generate(instance, helper);
        }
        case type::drop_foreign_key:
        {
            auto& instance = *static_cast<operations::drop_foreign_key*>(&operation);
            return generate(instance, helper);
        }
        case type::add_unique_constraint:
        {
            auto& instance = *static_cast<operations::add_unique_constraint*>(&operation);
            return generate(instance, helper);
        }
        case type::drop_unique_constraint:
        {
            auto& instance = *static_cast<operations::drop_unique_constraint*>(&operation);
            return generate(instance, helper);
        }
        default:
        {
            throw dodbm::exception("Unhandled operation type (" + std::to_string(static_cast<uint32_t>(operation.get_type())) + ")");
        }
    }
}

std::queue<dodbm::command> dodbm::sql_generator::generate(std::queue<std::shared_ptr<operation>> operations, const sql_generator_helper& helper)
{
    std::queue<command> commands;

    while (!operations.empty())
    {
        auto& operation = *operations.front();
        commands.emplace(generate(operation, helper));

        operations.pop();
    }

    return commands;
}

dodbm::command dodbm::sql_generator::generate(const operations::alter_database& operation, const sql_generator_helper& helper)
{
    const auto& collation = operation.get_collation();

    if (collation.empty())
    {
        throw dodbm::exception("Operation \"alter_database\" requires a valid collation");
    }

    const auto& charset = collation.get_charset();

    command result;
    result << "ALTER DATABASE "
           << helper.delimit_identifier(operation.get_name());

    if (!collation.empty())
    {
        result << " ";
        generate_collation(result, collation);
    }

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::drop_schema& operation, const sql_generator_helper& helper)
{
    command result;
    result << "DROP SCHEMA "
           << helper.delimit_identifier(operation.get_name());

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::ensure_schema& operation, const sql_generator_helper& helper)
{
    const auto& collation = operation.get_collation();
    const auto& charset = collation.get_charset();

    command result;
    result << "CREATE SCHEMA IF NOT EXISTS "
           << helper.delimit_identifier(operation.get_name());

    if (!collation.empty())
    {
        result << " ";
        generate_collation(result, collation);
    }

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::alter_table& operation, const sql_generator_helper& helper)
{
    command result;
    result << "ALTER TABLE "
           << helper.delimit_identifier(operation.get_schema(), operation.get_name());

    const auto& engine = operation.get_engine();
    const auto& collation = operation.get_collation();
    const auto& comment = operation.get_comment();

    if (engine.empty() && collation.empty() && comment.empty())
    {
        throw dodbm::exception("Operation \"alter_table\" requires at least one valid option");
    }

    generate_table_options(result, helper, operation.get_engine(), operation.get_collation(), operation.get_comment());

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::create_table& operation, const sql_generator_helper& helper)
{
    command result;
    result << "CREATE TABLE "
           << helper.delimit_identifier(operation.get_schema(), operation.get_name())
           << " (";

    const auto& columns = operation.get_columns();
    for (auto it = columns.begin(); it != columns.end(); ++it)
    {
        if (it != columns.begin())
        {
            result << ", ";
        }

        auto column = *it;
        generate_column(result, helper, column->get_name(), column->get_column_type(), column->get_max_length(), column->get_values(), column->get_default_value(), column->get_collation(),
                        column->get_attribute(), column->is_nullable(), column->is_auto_incremented(), column->get_comment());
    }

    auto primary_key = operation.get_primary_key();
    if (primary_key)
    {
        result << " ";
        generate_primary_key(result, helper, primary_key->get_name(), primary_key->get_column(), primary_key->get_comment());
    }

    const auto& foreign_keys = operation.get_foreign_keys();
    if (!foreign_keys.empty())
    {
        result << " ";

        for (auto it = foreign_keys.begin(); it != foreign_keys.end(); it++)
        {
            auto foreign_key = *it;
            if (it != foreign_keys.begin())
            {
                result << ", ";
            }

            generate_foreign_key(result, helper, foreign_key->get_name(), foreign_key->get_column(), foreign_key->get_in_schema(), foreign_key->get_from_table(), foreign_key->get_on_column(),
                                 foreign_key->get_on_delete(), foreign_key->get_on_update());
        }
    }

    const auto& unique_constraints = operation.get_unique_constraints();
    if (!unique_constraints.empty())
    {
        result << " ";

        for (auto it = unique_constraints.begin(); it != unique_constraints.end(); it++)
        {
            auto unique_constraint = *it;
            if (it != unique_constraints.begin())
            {
                result << ", ";
            }

            generate_unique_constraint(result, helper, unique_constraint->get_name(), unique_constraint->get_columns(), unique_constraint->get_comment());
        }
    }

    result << ")";

    generate_table_options(result, helper, operation.get_engine(), operation.get_collation(), operation.get_comment());

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::drop_table& operation, const sql_generator_helper& helper)
{
    command result;
    result << "DROP TABLE "
           << helper.delimit_identifier(operation.get_schema(), operation.get_name());

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::rename_table& operation, const sql_generator_helper& helper)
{
    command result;
    result << "RENAME TABLE "
           << helper.delimit_identifier(operation.get_schema(), operation.get_name())
           << " TO "
           << helper.delimit_identifier(operation.get_schema(), operation.get_new_name());

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::add_column& operation, const sql_generator_helper& helper)
{
    command result;
    result << "ALTER TABLE "
           << helper.delimit_identifier(operation.get_schema(), operation.get_table())
           << " ADD COLUMN ";

    generate_column(result, helper, operation.get_name(), operation.get_column_type(), operation.get_max_length(), operation.get_values(), operation.get_default_value(), operation.get_collation(),
                    operation.get_attribute(), operation.is_nullable(), operation.is_auto_incremented(), operation.get_comment(), operation.get_move_first(), operation.get_move_after());

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::alter_column& operation, const sql_generator_helper& helper)
{
    command result;
    result << "ALTER TABLE "
           << helper.delimit_identifier(operation.get_schema(), operation.get_table())
           << " MODIFY COLUMN ";

    generate_column(result, helper, operation.get_name(), operation.get_column_type(), operation.get_max_length(), operation.get_values(), operation.get_default_value(), operation.get_collation(),
                    operation.get_attribute(), operation.is_nullable(), operation.is_auto_incremented(), operation.get_comment(), operation.get_move_first(), operation.get_move_after());

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::drop_column& operation, const sql_generator_helper& helper)
{
    command result;
    result << "ALTER TABLE "
           << helper.delimit_identifier(operation.get_schema(), operation.get_table())
           << " DROP COLUMN "
           << helper.delimit_identifier(operation.get_name());

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::rename_column& operation, const sql_generator_helper& helper)
{
    command result;
    result << "ALTER TABLE "
           << helper.delimit_identifier(operation.get_schema(), operation.get_table())
           << " RENAME COLUMN "
           << helper.delimit_identifier(operation.get_name())
           << " TO "
           << helper.delimit_identifier(operation.get_new_name());

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::add_primary_key& operation, const sql_generator_helper& helper)
{
    command result;
    result << "ALTER TABLE "
           << helper.delimit_identifier(operation.get_schema(), operation.get_table())
           << " ADD ";

    generate_primary_key(result, helper, operation.get_name(), operation.get_column(), operation.get_comment());

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::drop_primary_key& operation, const sql_generator_helper& helper)
{
    command result;
    result << "ALTER TABLE "
           << helper.delimit_identifier(operation.get_schema(), operation.get_table())
           << " DROP PRIMARY KEY";

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::add_foreign_key& operation, const sql_generator_helper& helper)
{
    command result;
    result << "ALTER TABLE "
           << helper.delimit_identifier(operation.get_schema(), operation.get_table())
           << " ADD ";

    generate_foreign_key(result, helper, operation.get_name(), operation.get_column(), operation.get_in_schema(), operation.get_from_table(), operation.get_on_column(), operation.get_on_delete(),
                         operation.get_on_update());

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::drop_foreign_key& operation, const sql_generator_helper& helper)
{
    command result;
    result << "ALTER TABLE "
           << helper.delimit_identifier(operation.get_schema(), operation.get_table())
           << " DROP FOREIGN KEY "
           << helper.delimit_identifier(operation.get_name());

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::add_unique_constraint& operation, const sql_generator_helper& helper)
{
    command result;
    result << "ALTER TABLE "
           << helper.delimit_identifier(operation.get_schema(), operation.get_table())
           << " ADD ";

    generate_unique_constraint(result, helper, operation.get_name(), operation.get_columns(), operation.get_comment());

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::drop_unique_constraint& operation, const sql_generator_helper& helper)
{
    command result;
    result << "ALTER TABLE "
           << helper.delimit_identifier(operation.get_schema(), operation.get_table())
           << " DROP CONSTRAINT "
           << helper.delimit_identifier(operation.get_name());

    return result;
}

void dodbm::sql_generator::generate_column(command& command, const sql_generator_helper& helper, const std::string& name, const std::string& type, const size_t max_length,
                                           const std::vector<std::string>& values, const std::string& default_value, const collation& collation, const dodbm::column_attribute attribute,
                                           bool is_nullable, bool is_auto_incremented, const std::string& comment, bool move_first, const std::string& move_after)
{
    if (type.empty())
    {
        throw dodbm::exception("Column \"" + name + "\" require a valid type");
    }

    command << helper.delimit_identifier(name)
            << " "
            << type;

    // Append values or length.
    if (!values.empty())
    {
        command << "(";

        for (auto it = values.begin(); it != values.end(); ++it)
        {
            if (it != values.begin())
            {
                command << ", ";
            }

            command << helper.escape_literal(*it);
        }

        command << ")";
    }
    else if (max_length > 0)
    {
        command << "(" << max_length << ")";
    }

    // Append the others.
    switch (attribute)
    {
        case dodbm::column_attribute::binary:
        {
            command << " BINARY";
            break;
        }
        case dodbm::column_attribute::on_update_current_timestamp:
        {
            command << " on update CURRENT_TIMESTAMP";
            break;
        }
        case dodbm::column_attribute::unsigned_normal:
        {
            command << " UNSIGNED";
            break;
        }
        case dodbm::column_attribute::unsigned_zerofill:
        {
            command << " UNSIGNED_ZEROFILL";
            break;
        }
    }

    if (!collation.empty())
    {
        command << " ";
        generate_collation(command, collation);
    }

    if (is_nullable)
    {
        command << " NULL";
    }
    else
    {
        command << " NOT NULL";
    }

    if (!default_value.empty())
    {
        command << " DEFAULT " << helper.escape_literal(default_value);
    }

    if (is_auto_incremented)
    {
        command << " AUTO_INCREMENT";
    }

    if (!comment.empty())
    {
        command << " ";
        generate_comment(command, helper, comment);
    }

    if (move_first)
    {
        command << " FIRST";
    }
    else if (!move_after.empty())
    {
        command << " AFTER " << helper.delimit_identifier(move_after);
    }
}

void dodbm::sql_generator::generate_column_list(command& command, const sql_generator_helper& helper, const std::vector<std::string>& columns)
{
    for (auto it = columns.begin(); it != columns.end(); ++it)
    {
        if (it != columns.begin())
        {
            command << ", ";
        }

        command << helper.delimit_identifier(*it);
    }
}

void dodbm::sql_generator::generate_table_options(command& command, const sql_generator_helper& helper, const std::string& engine, const collation& collation, const std::string& comment)
{
    if (!engine.empty())
    {
        command << " ENGINE " << engine;
    }

    if (!collation.empty())
    {
        command << " ";
        generate_collation(command, collation);
    }

    if (!comment.empty())
    {
        command << " ";
        generate_comment(command, helper, comment);
    }
}

void dodbm::sql_generator::generate_collation(command& command, const collation& collation)
{
    const auto& charset = collation.get_charset();
    command << "CHARACTER SET " << charset << " COLLATE " << collation;
}

void dodbm::sql_generator::generate_comment(command& command, const sql_generator_helper& helper, const std::string& comment)
{
    command << "COMMENT " << helper.escape_literal(comment);
}

void dodbm::sql_generator::generate_primary_key(command& command, const sql_generator_helper& helper, const std::string& name, const std::string& column, const std::string& comment)
{
    command << "PRIMARY KEY";

    if (!name.empty())
    {
        command << " " << helper.delimit_identifier(name);
    }

    command << " ("
            << helper.delimit_identifier(column)
            << ")";

    if (!comment.empty())
    {
        command << " ";
        generate_comment(command, helper, comment);
    }
}

void dodbm::sql_generator::generate_foreign_key(command& command, const sql_generator_helper& helper, const std::string& name, const std::string& column, const std::string& in_schema,
                                                const std::string& from_table, const std::string& on_column, const std::string& on_delete, const std::string& on_update)
{
    command << "FOREIGN KEY";

    if (!name.empty())
    {
        command << " " << helper.delimit_identifier(name);
    }

    command << " ("
            << helper.delimit_identifier(column)
            << ") REFERENCES "
            << helper.delimit_identifier(in_schema, from_table)
            << " ("
            << helper.delimit_identifier(on_column)
            << ") ON DELETE "
            << on_delete
            << " ON UPDATE "
            << on_update;
}

void dodbm::sql_generator::generate_unique_constraint(command& command, const sql_generator_helper& helper, const std::string& name, const std::vector<std::string>& columns, const std::string& comment)
{
    command << "UNIQUE";

    if (!name.empty())
    {
        command << " " << helper.delimit_identifier(name);
    }

    command << " (";

    generate_column_list(command, helper, columns);

    command << ")";

    if (!comment.empty())
    {
        command << " ";
        generate_comment(command, helper, comment);
    }
}
