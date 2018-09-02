#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/drop_index.hpp>

#include <dodbm/builders/helpers/has_schema.hpp>
#include <dodbm/builders/helpers/has_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class drop_index : public builders::operation<operations::drop_index>
            , public helpers::has_schema<drop_index>
            , public helpers::has_table<drop_index>
        {
        public:

            using operation::operation;
        };
    }
}