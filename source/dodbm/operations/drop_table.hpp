#pragma once

#include <string>

#include <dodbm/operation.hpp>

namespace dodbm
{
    namespace operations
    {
        class drop_table : public operation
        {
        public:

            drop_table(const std::string& name);
            ~drop_table() = default;

            type get_type() const final;

            const std::string& get_name() const;

        private:

            std::string m_name;
        };
    }
}