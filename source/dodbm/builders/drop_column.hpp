#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/drop_column.hpp>

#include <dodbm/builders/helpers/has_schema.hpp>
#include <dodbm/builders/helpers/has_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class drop_column : public builders::operation<operations::drop_column>
            , public helpers::has_schema<drop_column>
            , public helpers::has_table<drop_column>
        {
        public:

            using operation::operation;
        };
    }
}