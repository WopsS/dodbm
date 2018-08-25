#pragma once

#include <dodbm/operations/alter_table.hpp>
#include <dodbm/operations/create_table.hpp>
#include <dodbm/operations/drop_table.hpp>
#include <dodbm/operations/rename_table.hpp>

namespace dodbm
{
    class base_provider
    {
    public:

        base_provider() = default;
        ~base_provider() = default;

        virtual void start_transaction() = 0;
        virtual void commit() = 0;
        virtual void rollback() = 0;

        virtual std::string compile(operations::alter_table* operation) = 0;
        virtual std::string compile(operations::create_table* operation) = 0;
        virtual std::string compile(operations::drop_table* operation) = 0;
        virtual std::string compile(operations::rename_table* operation) = 0;

        virtual bool execute(const std::string& sql) = 0;
    };
}