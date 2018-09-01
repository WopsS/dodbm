#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/add_primary_key.hpp>

#include <dodbm/builders/helpers/has_column.hpp>
#include <dodbm/builders/helpers/has_comment.hpp>
#include <dodbm/builders/helpers/has_schema.hpp>
#include <dodbm/builders/helpers/has_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class add_primary_key : public builders::operation<operations::add_primary_key>
            , public helpers::has_column<add_primary_key>
            , public helpers::has_comment<add_primary_key>
            , public helpers::has_schema<add_primary_key>
            , public helpers::has_table<add_primary_key>
        {
        public:

            using operation::operation;
        };
    }
}