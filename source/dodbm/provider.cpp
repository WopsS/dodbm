#include <dodbm/provider.hpp>

const dodbm::sql_generator dodbm::provider::get_generator() const
{
    return sql_generator();
}

const dodbm::history_repository dodbm::provider::get_history_repository() const
{
    return history_repository();
}

void dodbm::provider::execute(std::queue<command> commands)
{
    while (!commands.empty())
    {
        auto& command = commands.front();
        get_connection()->execute_non_query(command.get_text());

        commands.pop();
    }
}

void dodbm::provider::start_transaction()
{
    get_connection()->start_transaction();
}

void dodbm::provider::commit()
{
    get_connection()->commit();
}

void dodbm::provider::rollback()
{
    get_connection()->rollback();
}
