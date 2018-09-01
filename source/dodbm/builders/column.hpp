#pragma once

#include <dodbm/builders/operation.hpp>

#include <dodbm/operations/helpers/column.hpp>

#include <dodbm/builders/helpers/has_collation.hpp>
#include <dodbm/builders/helpers/has_comment.hpp>
#include <dodbm/builders/helpers/has_schema.hpp>
#include <dodbm/builders/helpers/has_table.hpp>

namespace dodbm
{
    namespace builders
    {
        template<typename T, typename Operation>
        class column : public builders::operation<Operation>
            , public helpers::has_collation<T>
            , public helpers::has_comment<T>
            , public helpers::has_schema<T>
            , public helpers::has_table<T>
        {
        public:

            using operation::operation;

            const T& max_length(uint64_t max_length) const
            {
                m_operation->set_max_length(max_length);
                return *static_cast<const T*>(this);
            }

            const T& values(std::vector<std::string> values) const
            {
                m_operation->set_values(std::move(values));
                return *static_cast<const T*>(this);
            }

            const T& default_value(dodbm::column_default value) const
            {
                m_operation->set_default_value(value);
                return *static_cast<const T*>(this);
            }

            const T& default_value(const std::string& value) const
            {
                m_operation->set_default_value(value);
                return *static_cast<const T*>(this);
            }

            const T& nullable() const
            {
                m_operation->set_nullable(true);
                return *static_cast<const T*>(this);
            }

            const T& not_nullable() const
            {
                m_operation->set_nullable(false);
                return *static_cast<const T*>(this);
            }

            const T& auto_incremented() const
            {
                m_operation->set_auto_incremented(true);
                return *static_cast<const T*>(this);
            }

            const T& not_auto_incremented() const
            {
                m_operation->set_auto_incremented(false);
                return *static_cast<const T*>(this);
            }

            const T& move_first() const
            {
                m_operation->set_move_first();
                return *static_cast<const T*>(this);
            }

            const T& move_after(const std::string& column_name) const
            {
                m_operation->set_move_after(column_name);
                return *static_cast<const T*>(this);
            }

            // Attributes.

            const T& binary() const
            {
                return attribute(dodbm::column_attribute::binary);
            }

            const T& on_update_current_timestamp() const
            {
                return attribute(dodbm::column_attribute::on_update_current_timestamp);
            }

            const T& unsigned_normal() const
            {
                return attribute(dodbm::column_attribute::unsigned_normal);
            }

            const T& unsigned_zerofill() const
            {
                return attribute(dodbm::column_attribute::unsigned_zerofill);
            }

        private:

            const T& attribute(dodbm::column_attribute attribute) const
            {
                m_operation->set_attribute(attribute);
                return *static_cast<const T*>(this);
            }
        };
    }
}