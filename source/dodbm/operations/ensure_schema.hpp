#pragma once

#include <dodbm/operation.hpp>

#include <dodbm/operations/helpers/has_collation.hpp>
#include <dodbm/operations/helpers/has_name.hpp>

namespace dodbm
{
    namespace operations
    {
        class ensure_schema : public operation
            , public helpers::has_collation
            , public helpers::has_name
        {
        public:

            using has_name::has_name;

            type get_type() const final;
        };
    }
}