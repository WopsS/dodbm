#pragma once

#include <dodbm/operations/base_operation.hpp>

namespace dodbm
{
    namespace operations
    {
        class alter_table : public base_operation
        {
        public:

            alter_table(const std::string& name);
            ~alter_table() = default;

            void set_engine(const std::string& name);

            void set_collation(const std::string& name);

            void set_comment(const std::string& text);

        private:
            std::string m_name;

            std::string m_engine;

            std::string m_collation;

            std::string m_comment;
        };
    }
}