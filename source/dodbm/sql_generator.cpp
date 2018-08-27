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
    const auto& charset = collation.get_charset();

    command result;
    result << "ALTER DATABASE "
           << helper.delimit_identifier(operation.get_name())
           << " DEFAULT CHARSET=" << charset
           << " COLLATE=" << collation;

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::alter_table& operation, const sql_generator_helper& helper)
{
    command result;
    result << "ALTER TABLE "
           << helper.delimit_identifier(operation.get_schema(), operation.get_name())
           << " ";

    generate_table_options(result, helper, operation.get_engine(), operation.get_collation(), operation.get_comment());

    return result;
}

dodbm::command dodbm::sql_generator::generate(const operations::create_table& operation, const sql_generator_helper& helper)
{
    command result;
    result << "CREATE TABLE "
           << helper.delimit_identifier(operation.get_schema(), operation.get_name())
           << " ()";

    // TODO: Append columns.

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

void dodbm::sql_generator::generate_table_options(command& command, const sql_generator_helper& helper, const std::string& engine, const collation& collation, const std::string& comment)
{
    if (!engine.empty())
    {
        command << " ENGINE " << engine;
    }

    if (!collation.empty())
    {
        const auto& charset = collation.get_charset();
        command << " DEFAULT CHARSET=" << charset << " COLLATE=" << collation;
    }

    if (!comment.empty())
    {
        command << " COMMENT=" << helper.escape_literal(comment);
    }
}
