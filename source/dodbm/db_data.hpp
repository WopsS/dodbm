#pragma once

#include <string>

#include <dodbm/db_value.hpp>

namespace dodbm
{
    class db_data
    {
    public:

        std::string column;
        db_value value;
    };
}