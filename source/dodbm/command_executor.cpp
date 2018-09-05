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

        if (command.is_allowed_in_prepared_statements())
        {
            m_connection->execute_non_query(command.get_text(), command.get_parameters());
        }
        else
        {
            m_connection->execute_non_query(command.get_text());
        }

        commands.pop();
    }
}
