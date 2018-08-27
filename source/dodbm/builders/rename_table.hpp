#pragma once

#include <string>

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/rename_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class rename_table : public builders::operation<operations::rename_table>
        {
        public:

            using operation::operation;

            void to(const std::string& name);
        };
    }
}