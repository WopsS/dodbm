#include <dodbm/history_repository.hpp>
#include <dodbm/command.hpp>

bool dodbm::history_repository::exists() const
{
    return false;
}

void dodbm::history_repository::create()
{
}

const std::string dodbm::history_repository::get_last_applied_migration(connection* connection, const sql_generator_helper& helper) const
{
    command command;
    command << "SELECT "
            << helper.delimit_identifier(get_table_name(), get_id_column_name())
            << " FROM "
            << helper.delimit_identifier(get_table_name())
            << " ORDER BY "
            << helper.delimit_identifier(get_table_name(), get_id_column_name())
            << " ASC "
            << "LIMIT 1";

    auto query_result = connection->execute_query(command.get_text());
    if (!query_result.empty())
    {
        return query_result.first().get("name").as_string();
    }

    return "";
}

void dodbm::history_repository::get_insert_operation(const std::string& name)
{
}

void dodbm::history_repository::get_delete_operation(const std::string& name)
{
}

const std::string dodbm::history_repository::get_table_name() const
{
    return "__migrations_history";
}

const std::string dodbm::history_repository::get_id_column_name() const
{
    return "migration_id";
}
