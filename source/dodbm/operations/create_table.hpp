#pragma once

#include <dodbm/collation.hpp>
#include <dodbm/operation_with_schema.hpp>

namespace dodbm
{
    namespace operations
    {
        class create_table : public operation_with_schema
        {
        public:

            create_table(const std::string& name);
            ~create_table() = default;

            type get_type() const final;

            const std::string& get_name() const;

            void set_engine(const std::string& name);
            const std::string& get_engine() const;

            void set_collation(collation value);
            const collation& get_collation() const;

            void set_comment(const std::string& text);
            const std::string& get_comment() const;

        private:

            std::string m_name;

            std::string m_engine;
            collation m_collation;
            std::string m_comment;
        };
    }
}