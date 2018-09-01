#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/add_unique_constraint.hpp>

#include <dodbm/builders/helpers/has_columns.hpp>
#include <dodbm/builders/helpers/has_comment.hpp>
#include <dodbm/builders/helpers/has_schema.hpp>
#include <dodbm/builders/helpers/has_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class add_unique_constraint : public builders::operation<operations::add_unique_constraint>
            , public helpers::has_columns<add_unique_constraint>
            , public helpers::has_comment<add_unique_constraint>
            , public helpers::has_schema<add_unique_constraint>
            , public helpers::has_table<add_unique_constraint>
        {
        public:

            using operation::operation;
        };
    }
}