#pragma once

#include <dodbm/operation.hpp>

#include <dodbm/operations/helpers/has_name.hpp>
#include <dodbm/operations/helpers/has_schema.hpp>
#include <dodbm/operations/helpers/has_table.hpp>

namespace dodbm
{
    namespace operations
    {
        class drop_column : public operation
            , public helpers::has_name
            , public helpers::has_schema
            , public helpers::has_table
        {
        public:

            using has_name::has_name;

            type get_type() const final;
        };
    }
}