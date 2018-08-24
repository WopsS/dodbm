#pragma once

#include <dodbm/operations/base_operation.hpp>

namespace dodbm
{
    namespace operations
    {
        class drop_table : public base_operation
        {
        public:

            drop_table(const std::string& name);
            ~drop_table() = default;

        private:

            std::string m_name;
        };
    }
}