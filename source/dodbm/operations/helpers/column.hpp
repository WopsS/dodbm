#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include <dodbm/db_value.hpp>

#include <dodbm/operations/helpers/has_collation.hpp>
#include <dodbm/operations/helpers/has_comment.hpp>
#include <dodbm/operations/helpers/has_required_name.hpp>
#include <dodbm/operations/helpers/has_schema.hpp>
#include <dodbm/operations/helpers/has_table.hpp>

namespace dodbm
{
    namespace operations
    {
        namespace helpers
        {
            class column : public helpers::has_collation
                , public helpers::has_comment
                , public helpers::has_required_name
                , public helpers::has_schema
                , public helpers::has_table
            {
            public:

                enum class attribute : uint8_t
                {
                    none,
                    binary,
                    unsigned_normal, // Not zerofilled.
                    unsigned_zerofill,
                    on_update_current_timestamp,
                };

                enum class default_value : uint8_t
                {
                    null,
                    current_timestamp
                };

                column(const std::string& name);
                virtual ~column() = default;

                void set_column_type(const std::string& type);
                const std::string& get_column_type() const;

                void set_max_length(uint64_t max_length);
                uint64_t get_max_length() const;

                void set_decimals(uint8_t decimals);
                uint8_t get_decimals() const;

                void set_values(std::vector<std::string> values);
                const std::vector<std::string>& get_values() const;

                void set_default_value(default_value value);
                void set_default_value(db_value value);

                const db_value& get_default_value() const;

                void set_attribute(attribute attribute);
                attribute get_attribute() const;

                void set_nullable(bool nullable);
                bool is_nullable() const;

                void set_auto_incremented(bool auto_incremented);
                bool is_auto_incremented() const;

                void set_move_first();
                bool get_move_first() const;

                void set_move_after(const std::string& column_name);
                const std::string& get_move_after() const;

            private:

                std::string m_column_type;

                uint64_t m_max_length;
                uint8_t m_decimals;
                std::vector<std::string> m_values;

                db_value m_default_value;
                attribute m_attribute;
                bool m_is_nullable;
                bool m_is_auto_incremented;

                bool m_move_first;
                std::string m_move_after;
            };
        }
    }

    using column_default = operations::helpers::column::default_value;
    using column_attribute = operations::helpers::column::attribute;
}