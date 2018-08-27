#pragma once

#include <dodbm/builders/operation_with_schema.hpp>
#include <dodbm/operations/drop_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class drop_table : public builders::operation_with_schema<drop_table, operations::drop_table>
        {
        public:

            using operation_with_schema::operation_with_schema;
        };
    }
}