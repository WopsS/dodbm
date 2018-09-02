#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/rename_index.hpp>

#include <dodbm/builders/helpers/has_collation.hpp>
#include <dodbm/builders/helpers/has_new_name.hpp>
#include <dodbm/builders/helpers/has_schema.hpp>
#include <dodbm/builders/helpers/has_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class rename_index : public builders::operation<operations::rename_index>
            , public helpers::has_collation<rename_index>
            , public helpers::has_new_name<rename_index>
            , public helpers::has_table<rename_index>
        {
        public:

            using operation::operation;
        };
    }
}