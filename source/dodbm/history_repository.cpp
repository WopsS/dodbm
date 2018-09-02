#include <dodbm/history_repository.hpp>
#include <dodbm/command.hpp>
#include <dodbm/exception.hpp>

#include <dodbm/builders/create_table.hpp>

namespace
{
    struct varchar
    {
        static constexpr auto name = "VARCHAR";
    };
}

bool dodbm::history_repository::exists(connection* connection, const sql_generator_helper& helper) const
{
    command command;
    command << "SELECT 1"
            << " FROM "
            << helper.delimit_identifier("information_schema", "tables")
            << " WHERE "
            << "table_schema = " << helper.delimit_identifier(connection->get_schema_name())
            << " AND "
            << "table_name = " << helper.delimit_identifier(get_table_name())
            << " LIMIT 1";

    auto query_result = connection->execute_query(command.get_text());
    if (!query_result.empty())
    {
        return true;
    }

    return false;
}

void dodbm::history_repository::create(connection* connection, const sql_generator& generator, const sql_generator_helper& helper)
{
    std::shared_ptr<operations::create_table> operation(new operations::create_table(get_table_name()));
    builders::create_table builder(operation);

    builder.columns([&](columns_builder& builder)
    {
        builder.add<varchar>(get_id_column_name())
               .max_length(256);
    })
    .constraints([&](constraints_builder& builder)
    {
        builder.primary_key()
               .column(get_id_column_name())
               .table(get_table_name());
    });

    auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(operation.get()), helper);

    try
    {
        connection->execute_non_query(command.get_text(), command.get_parameters());
        connection->commit();
    }
    catch (dodbm::exception)
    {
        connection->rollback();
        throw;
    }
}

const std::string dodbm::history_repository::get_last_applied_migration(connection* connection, const sql_generator_helper& helper) const
{
    command command;
    command << "SELECT "
            << helper.delimit_identifier(get_id_column_name())
            << " FROM "
            << helper.delimit_identifier(get_table_name())
            << " ORDER BY "
            << helper.delimit_identifier(get_id_column_name())
            << " ASC "
            << "LIMIT 1";

    auto query_result = connection->execute_query(command.get_text());
    if (!query_result.empty())
    {
        return query_result.first().get("name").get_string();
    }

    return "";
}

std::shared_ptr<dodbm::operations::insert_data> dodbm::history_repository::get_insert_operation(const std::string& migration_name)
{
    std::shared_ptr<operations::insert_data> operation(new operations::insert_data({ { get_id_column_name(), migration_name } }));
    operation->set_table(get_table_name());

    return operation;
}

std::shared_ptr<dodbm::operations::delete_data> dodbm::history_repository::get_delete_operation(const std::string& migration_name)
{
    std::shared_ptr<operations::delete_data> operation(new operations::delete_data());
    operation->set_table(get_table_name());
    operation->set_where_data({ { get_id_column_name(), migration_name } });

    return operation;
}

const std::string dodbm::history_repository::get_table_name() const
{
    return "__migrations_history";
}

const std::string dodbm::history_repository::get_id_column_name() const
{
    return "migration_id";
}
