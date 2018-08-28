#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/rename_table.hpp>

#include <dodbm/builders/helpers/has_collation.hpp>
#include <dodbm/builders/helpers/has_schema.hpp>

namespace dodbm
{
    namespace builders
    {
        class rename_table : public builders::operation<operations::rename_table>
            , public helpers::has_collation<rename_table>
            , public helpers::has_schema<rename_table>
        {
        public:

            using operation::operation;

            const rename_table& to(const std::string& name) const;
        };
    }
}