#pragma once

#include <dodbm/sql_generator.hpp>

namespace dodbm
{
    class provider
    {
    public:

        provider() = default;
        ~provider() = default;

        virtual const sql_generator get_generator() const;
    };
}