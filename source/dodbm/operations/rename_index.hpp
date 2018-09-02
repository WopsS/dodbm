#pragma once

#include <dodbm/operation.hpp>

#include <dodbm/operations/helpers/has_new_name.hpp>
#include <dodbm/operations/helpers/has_required_name.hpp>
#include <dodbm/operations/helpers/has_schema.hpp>
#include <dodbm/operations/helpers/has_table.hpp>

namespace dodbm
{
    namespace operations
    {
        class rename_index : public operation
            , public helpers::has_new_name
            , public helpers::has_required_name
            , public helpers::has_schema
            , public helpers::has_table
        {
        public:

            using has_required_name::has_required_name;

            type get_type() const final;
        };
    }
}