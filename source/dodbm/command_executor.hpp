#pragma once

#include <queue>

#include <dodbm/command.hpp>
#include <dodbm/connection.hpp>

namespace dodbm
{
    class command_executor
    {
    public:

        command_executor(connection* connection);
        ~command_executor() = default;

        void execute(std::queue<command> commands);

    private:

        connection* m_connection;
    };
}