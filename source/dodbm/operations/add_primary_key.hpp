#pragma once

#include <string>

#include <dodbm/operation.hpp>

#include <dodbm/operations/helpers/has_column.hpp>
#include <dodbm/operations/helpers/has_comment.hpp>
#include <dodbm/operations/helpers/has_optional_name.hpp>
#include <dodbm/operations/helpers/has_schema.hpp>
#include <dodbm/operations/helpers/has_table.hpp>

namespace dodbm
{
    namespace operations
    {
        class add_primary_key : public operation
            , public helpers::has_column
            , public helpers::has_comment
            , public helpers::has_optional_name
            , public helpers::has_schema
            , public helpers::has_table
        {
        public:

            using has_optional_name::has_optional_name;

            type get_type() const final;
        };
    }
}