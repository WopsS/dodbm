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

dodbm::db_result mocks::connection::execute_query(const std::string& text)
{
    return dodbm::db_result({});
}