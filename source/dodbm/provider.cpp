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
        command.execute_non_query();

        commands.pop();
    }
}
