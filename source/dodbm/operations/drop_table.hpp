#pragma once

#include <dodbm/operation.hpp>

#include <dodbm/operations/helpers/has_required_name.hpp>
#include <dodbm/operations/helpers/has_schema.hpp>

namespace dodbm
{
    namespace operations
    {
        class drop_table : public operation
            , public helpers::has_required_name
            , public helpers::has_schema
        {
        public:

            using has_required_name::has_required_name;

            type get_type() const final;
        };
    }
}