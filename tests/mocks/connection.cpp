#include <mocks/connection.hpp>

void mocks::connection::start_transaction()
{
}

void mocks::connection::commit()
{
}

void mocks::connection::rollback()
{
}

void mocks::connection::execute_non_query(const std::string& text)
{
}

void mocks::connection::execute_non_query(const std::string& text, const std::vector<dodbm::db_value>& parameters)
{
}

dodbm::db_result mocks::connection::execute_query(const std::string& text, const std::vector<dodbm::db_value>& parameters)
{
    return dodbm::db_result({});
}

std::string mocks::connection::get_schema_name() const
{
    return "mock";
}
