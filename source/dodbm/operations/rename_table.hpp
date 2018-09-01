#pragma once

#include <dodbm/operation.hpp>

#include <dodbm/operations/helpers/has_name.hpp>
#include <dodbm/operations/helpers/has_new_name.hpp>
#include <dodbm/operations/helpers/has_schema.hpp>

namespace dodbm
{
    namespace operations
    {
        class rename_table : public operation
            , public helpers::has_name
            , public helpers::has_new_name
            , public helpers::has_schema
        {
        public:

            using has_name::has_name;

            type get_type() const final;
        };
    }
}