#pragma once

#include <dodbm/builders/operation_with_schema.hpp>
#include <dodbm/operations/rename_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class rename_table : public builders::operation_with_schema<rename_table, operations::rename_table>
        {
        public:

            using operation_with_schema::operation_with_schema;

            const rename_table& to(const std::string& name) const;
        };
    }
}