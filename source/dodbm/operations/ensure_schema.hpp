#pragma once

#include <dodbm/operation.hpp>

#include <dodbm/operations/helpers/has_collation.hpp>
#include <dodbm/operations/helpers/has_required_name.hpp>

namespace dodbm
{
    namespace operations
    {
        class ensure_schema : public operation
            , public helpers::has_collation
            , public helpers::has_required_name
        {
        public:

            using has_required_name::has_required_name;

            type get_type() const final;
        };
    }
}