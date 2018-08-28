#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/ensure_schema.hpp>

#include <dodbm/builders/helpers/has_collation.hpp>

namespace dodbm
{
    namespace builders
    {
        class ensure_schema : public builders::operation<operations::ensure_schema>
            , public helpers::has_collation<ensure_schema>
        {
        public:

            using operation::operation;
        };
    }
}