#pragma once

#include <queue>

#include <dodbm/command.hpp>
#include <dodbm/history_repository.hpp>
#include <dodbm/sql_generator.hpp>

namespace dodbm
{
    class provider
    {
    public:

        provider() = default;
        ~provider() = default;

        // Transaction.
        virtual void start_transaction() = 0;
        virtual void commit() = 0;
        virtual void rollback() = 0;

        virtual const sql_generator get_generator() const;

        virtual const history_repository get_history_repository() const;

        void execute(std::queue<command> commands);
    };
}