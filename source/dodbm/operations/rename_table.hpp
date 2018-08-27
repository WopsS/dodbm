#pragma once

#include <dodbm/operation_with_schema.hpp>

namespace dodbm
{
    namespace operations
    {
        class rename_table : public operation_with_schema
        {
        public:

            rename_table(const std::string& name);
            ~rename_table() = default;

            type get_type() const final;

            const std::string& get_name() const;

            void set_new_name(const std::string& name);
            const std::string& get_new_name() const;

        private:

            std::string m_name;
            std::string m_new_name;
        };
    }
}