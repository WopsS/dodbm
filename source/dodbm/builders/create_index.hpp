#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/create_index.hpp>

#include <dodbm/builders/helpers/has_columns.hpp>
#include <dodbm/builders/helpers/has_comment.hpp>
#include <dodbm/builders/helpers/has_schema.hpp>
#include <dodbm/builders/helpers/has_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class create_index : public builders::operation<operations::create_index>
            , public helpers::has_columns<create_index>
            , public helpers::has_comment<create_index>
            , public helpers::has_schema<create_index>
            , public helpers::has_table<create_index>
        {
        public:

            using operation::operation;
        };
    }
}