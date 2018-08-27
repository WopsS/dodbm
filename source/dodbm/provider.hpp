#pragma once

#include <dodbm/connection.hpp>
#include <dodbm/history_repository.hpp>
#include <dodbm/sql_generator.hpp>

namespace dodbm
{
    class provider
    {
    public:

        provider() = default;
        virtual ~provider() = default;

        virtual connection* get_connection() const = 0;

        virtual const history_repository get_history_repository() const;

        virtual const sql_generator get_sql_generator() const;
        virtual const sql_generator_helper get_sql_generator_helper() const;
    };
}