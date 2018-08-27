#pragma once

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
    };
}