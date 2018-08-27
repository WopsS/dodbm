#pragma once

#include <cstdint>

namespace dodbm
{
    class operation
    {
    public:

        enum class type : uint8_t
        {
            alter_database,

            alter_table,
            create_table,
            drop_table,
            rename_table
        };

        operation() = default;
        virtual ~operation() = default;

        virtual type get_type() const = 0;
    };
}