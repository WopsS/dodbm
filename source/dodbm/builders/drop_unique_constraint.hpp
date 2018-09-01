#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/drop_unique_constraint.hpp>

#include <dodbm/builders/helpers/has_schema.hpp>
#include <dodbm/builders/helpers/has_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class drop_unique_constraint : public builders::operation<operations::drop_unique_constraint>
            , public helpers::has_schema<drop_unique_constraint>
            , public helpers::has_table<drop_unique_constraint>
        {
        public:

            using operation::operation;
        };
    }
}