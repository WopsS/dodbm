#pragma once

#include <dodbm/operation.hpp>

#include <dodbm/operations/helpers/has_schema.hpp>
#include <dodbm/operations/helpers/has_table.hpp>
#include <dodbm/operations/helpers/has_where_data.hpp>

namespace dodbm
{
    namespace operations
    {
        class delete_data : public operation
            , public helpers::has_schema
            , public helpers::has_table
            , public helpers::has_where_data
        {
        public:

            type get_type() const final;
        };
    }
}