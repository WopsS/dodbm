#pragma once

#include <functional>

#include <dodbm/builders/columns.hpp>
#include <dodbm/builders/constraints.hpp>
#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/create_table.hpp>

#include <dodbm/builders/helpers/has_collation.hpp>
#include <dodbm/builders/helpers/has_comment.hpp>
#include <dodbm/builders/helpers/has_engine.hpp>
#include <dodbm/builders/helpers/has_schema.hpp>

namespace dodbm
{
    namespace builders
    {
        class create_table : public builders::operation<operations::create_table>
            , public helpers::has_comment<create_table>
            , public helpers::has_collation<create_table>
            , public helpers::has_engine<create_table>
            , public helpers::has_schema<create_table>
        {
        public:

            using operation::operation;

            const create_table& columns(std::function<void(columns_builder&)> func);

            const create_table& constraints(std::function<void(constraints_builder)> func) const;
        };
    }
}