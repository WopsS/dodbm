#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/rename_column.hpp>

#include <dodbm/builders/helpers/has_collation.hpp>
#include <dodbm/builders/helpers/has_new_name.hpp>
#include <dodbm/builders/helpers/has_schema.hpp>
#include <dodbm/builders/helpers/has_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class rename_column : public builders::operation<operations::rename_column>
            , public helpers::has_collation<rename_column>
            , public helpers::has_new_name<rename_column>
            , public helpers::has_schema<rename_column>
            , public helpers::has_table<rename_column>
        {
        public:

            using operation::operation;
        };
    }
}