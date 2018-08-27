#include <dodbm/command_executor.hpp>

dodbm::command_executor::command_executor(connection* connection)
    : m_connection(connection)
{
}

void dodbm::command_executor::execute(std::queue<command> commands)
{
    while (!commands.empty())
    {
        auto& command = commands.front();
        m_connection->execute_non_query(command.get_text());

        commands.pop();
    }
}
