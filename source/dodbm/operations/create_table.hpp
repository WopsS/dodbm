#pragma once

#include <dodbm/operations/base_operation.hpp>

namespace dodbm
{
    namespace operations
    {
        class create_table : public base_operation
        {
        public:

            create_table(const std::string& name);
            ~create_table() = default;

            void set_engine(const std::string& name);

            void set_collation(const std::string& name);

            void set_columns(std::function<void()> func);

            void set_constraints(std::function<void()> func);

            void set_comment(const std::string& text);

        private:

            std::string m_name;

            std::string m_engine;

            std::string m_collation;

            std::function<void()> m_columns;

            std::function<void()> m_constraints;

            std::string m_comment;
        };
    }
}