#pragma once

#include <queue>

#include <dodbm/command.hpp>
#include <dodbm/connection.hpp>
#include <dodbm/history_repository.hpp>
#include <dodbm/sql_generator.hpp>

namespace dodbm
{
    class provider
    {
    public:

        provider() = default;
        ~provider() = default;

        virtual const sql_generator get_generator() const;

        virtual const history_repository get_history_repository() const;

        void execute(std::queue<command> commands);

        // Transaction.
        void start_transaction();
        void commit();
        void rollback();

    protected:

        virtual connection* get_connection() const = 0;
    };
}