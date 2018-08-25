#pragma once

namespace dodbm
{
    namespace operations
    {
        enum class operation_type : uint8_t
        {
            alter_table,
            create_table,
            drop_table,
            rename_table
        };
    }
}