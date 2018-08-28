#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/drop_table.hpp>

#include <dodbm/builders/helpers/has_schema.hpp>

namespace dodbm
{
    namespace builders
    {
        class drop_table : public builders::operation<operations::drop_table>
            , public helpers::has_schema<drop_table>
        {
        public:

            using operation::operation;
        };
    }
}