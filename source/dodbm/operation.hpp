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

            ensure_schema,
            drop_schema,

            create_table,
            drop_table,
            alter_table,
            rename_table,

            add_column,
            drop_column,
            alter_column,
            rename_column,

            add_primary_key,
            drop_primary_key,

            add_foreign_key,
            drop_foreign_key,

            add_unique_constraint,
            drop_unique_constraint,

            create_index,
            drop_index,
            rename_index
        };

        operation() = default;
        virtual ~operation() = default;

        virtual type get_type() const = 0;
    };
}