#pragma once

#include <string>

#include <dodbm/db_result.hpp>
#include <dodbm/db_value.hpp>

namespace dodbm
{
    class connection
    {
    public:

        connection() = default;
        virtual ~connection() = default;

        virtual void start_transaction() = 0;
        virtual void commit() = 0;
        virtual void rollback() = 0;

        virtual void execute_non_query(const std::string& text) = 0;
        virtual void execute_non_query(const std::string& text, const std::vector<db_value>& parameters) = 0;

        virtual db_result execute_query(const std::string& text, const std::vector<db_value>& parameters = {}) = 0;

        virtual std::string get_schema_name() const = 0;
    };
}