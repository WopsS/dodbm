#pragma once

#include <dodbm/operations/base_operation.hpp>

namespace dodbm
{
    namespace operations
    {
        class rename_table : public base_operation
        {
        public:

            rename_table(const std::string& name);
            ~rename_table() = default;

            void set_new_name(const std::string& name);

        private:

            std::string m_name;

            std::string m_new_name;
        };
    }
}