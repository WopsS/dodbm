#pragma once

#include <dodbm/collation.hpp>
#include <dodbm/operation_with_schema.hpp>
#include <dodbm/storage_engine.hpp>

namespace dodbm
{
    namespace operations
    {
        class alter_table : public operation_with_schema
        {
        public:

            alter_table(const std::string& name);
            ~alter_table() = default;

            type get_type() const final;

            const std::string& get_name() const;

            void set_engine(storage_engine engine);
            const storage_engine& get_engine() const;

            void set_collation(collation value);
            const collation& get_collation() const;

            void set_comment(const std::string& text);
            const std::string& get_comment() const;

        private:

            std::string m_name;

            storage_engine m_engine;
            collation m_collation;
            std::string m_comment;
        };
    }
}