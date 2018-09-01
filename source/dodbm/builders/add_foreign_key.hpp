#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/add_foreign_key.hpp>

#include <dodbm/builders/helpers/has_column.hpp>
#include <dodbm/builders/helpers/has_schema.hpp>
#include <dodbm/builders/helpers/has_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class add_foreign_key : public builders::operation<operations::add_foreign_key>
            , public helpers::has_column<add_foreign_key>
            , public helpers::has_schema<add_foreign_key>
            , public helpers::has_table<add_foreign_key>
        {
        public:

            using operation::operation;

            const add_foreign_key& on_column(const std::string& name) const;
            const add_foreign_key& from_table(const std::string& name) const;
            const add_foreign_key& in_schema(const std::string& name) const;
        };
    }
}