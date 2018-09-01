#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/drop_primary_key.hpp>

#include <dodbm/builders/helpers/has_schema.hpp>
#include <dodbm/builders/helpers/has_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class drop_primary_key : public builders::operation<operations::drop_primary_key>
            , public helpers::has_schema<drop_primary_key>
            , public helpers::has_table<drop_primary_key>
        {
        public:

            using operation::operation;
        };
    }
}