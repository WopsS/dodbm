#pragma once

#include <string>

#include <dodbm/db_result.hpp>

namespace dodbm
{
    class connection
    {
    public:

        connection() = default;
        ~connection() = default;

        virtual void start_transaction() = 0;
        virtual void commit() = 0;
        virtual void rollback() = 0;

        virtual void execute_non_query(const std::string& text) = 0;
        virtual db_result execute_query(const std::string& text) = 0;
    };
}