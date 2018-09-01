#pragma once

#include <cstdint>
#include <string>

#include <dodbm/operation.hpp>

#include <dodbm/operations/helpers/has_column.hpp>
#include <dodbm/operations/helpers/has_optional_name.hpp>
#include <dodbm/operations/helpers/has_schema.hpp>
#include <dodbm/operations/helpers/has_table.hpp>

namespace dodbm
{
    namespace operations
    {
        class add_foreign_key : public operation
            , public helpers::has_column
            , public helpers::has_optional_name
            , public helpers::has_schema
            , public helpers::has_table
        {
        public:

            enum class action : uint8_t
            {
                cascade,
                restrict,
                set_null,
                no_action
            };

            add_foreign_key(const std::string& name = "");

            type get_type() const final;

            void set_on_column(const std::string& name);
            const std::string& get_on_column() const;

            void set_from_table(const std::string& name);
            const std::string& get_from_table() const;

            void set_in_schema(const std::string& name);
            const std::string& get_in_schema() const;

            void set_on_delete(action action);
            const std::string get_on_delete() const;

            void set_on_update(action action);
            const std::string get_on_update() const;

        private:

            const std::string get_action_string(action act) const;

            std::string m_column;
            std::string m_on_column;
            std::string m_from_table;
            std::string m_in_schema;

            action m_on_delete;
            action m_on_update;
        };
    }

    using constraint_action = operations::add_foreign_key::action;
}