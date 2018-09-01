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

            using base_t = builders::operation<Operation>;

            using base_t::operation;

            const T& max_length(uint64_t max_length)
            {
                base_t::m_operation->set_max_length(max_length);
                return *reinterpret_cast<const T*>(this);
            }

            const T& values(std::vector<std::string> values) const
            {
                base_t::m_operation->set_values(std::move(values));
                return *reinterpret_cast<const T*>(this);
            }

            const T& default_value(dodbm::column_default value) const
            {
                base_t::m_operation->set_default_value(value);
                return *reinterpret_cast<const T*>(this);
            }

            const T& default_value(const std::string& value) const
            {
                base_t::m_operation->set_default_value(value);
                return *reinterpret_cast<const T*>(this);
            }

            const T& nullable() const
            {
                base_t::m_operation->set_nullable(true);
                return *reinterpret_cast<const T*>(this);
            }

            const T& not_nullable() const
            {
                base_t::m_operation->set_nullable(false);
                return *reinterpret_cast<const T*>(this);
            }

            const T& auto_incremented() const
            {
                base_t::m_operation->set_auto_incremented(true);
                return *reinterpret_cast<const T*>(this);
            }

            const T& not_auto_incremented() const
            {
                base_t::m_operation->set_auto_incremented(false);
                return *reinterpret_cast<const T*>(this);
            }

            const T& move_first() const
            {
                base_t::m_operation->set_move_first();
                return *reinterpret_cast<const T*>(this);
            }

            const T& move_after(const std::string& column_name) const
            {
                base_t::m_operation->set_move_after(column_name);
                return *reinterpret_cast<const T*>(this);
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
                base_t::m_operation->set_attribute(attribute);
                return *reinterpret_cast<const T*>(this);
            }
        };
    }
}