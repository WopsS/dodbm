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
        template<typename Builder, typename Operation>
        class column : public builders::operation<Operation>
            , public helpers::has_collation<Builder>
            , public helpers::has_comment<Builder>
            , public helpers::has_schema<Builder>
            , public helpers::has_table<Builder>
        {
        public:

            using base_t = builders::operation<Operation>;

            using base_t::operation;

            const Builder& max_length(uint64_t max_length) const
            {
                base_t::m_operation->set_max_length(max_length);
                return *reinterpret_cast<const Builder*>(this);
            }

            const Builder& decimals(uint8_t decimals) const
            {
                base_t::m_operation->set_decimals(decimals);
                return *reinterpret_cast<const Builder*>(this);
            }

            const Builder& values(std::vector<std::string> values) const
            {
                base_t::m_operation->set_values(std::move(values));
                return *reinterpret_cast<const Builder*>(this);
            }

            template<typename T>
            const Builder& default_value(T value) const
            {
                base_t::m_operation->set_default_value(value);
                return *reinterpret_cast<const Builder*>(this);
            }

            const Builder& nullable() const
            {
                base_t::m_operation->set_nullable(true);
                return *reinterpret_cast<const Builder*>(this);
            }

            const Builder& not_nullable() const
            {
                base_t::m_operation->set_nullable(false);
                return *reinterpret_cast<const Builder*>(this);
            }

            const Builder& auto_incremented() const
            {
                base_t::m_operation->set_auto_incremented(true);
                return *reinterpret_cast<const Builder*>(this);
            }

            const Builder& not_auto_incremented() const
            {
                base_t::m_operation->set_auto_incremented(false);
                return *reinterpret_cast<const Builder*>(this);
            }

            const Builder& move_first() const
            {
                base_t::m_operation->set_move_first();
                return *reinterpret_cast<const Builder*>(this);
            }

            const Builder& move_after(const std::string& column_name) const
            {
                base_t::m_operation->set_move_after(column_name);
                return *reinterpret_cast<const Builder*>(this);
            }

            // Attributes.

            const Builder& no_attribute() const
            {
                return attribute(dodbm::column_attribute::none);
            }

            const Builder& binary() const
            {
                return attribute(dodbm::column_attribute::binary);
            }

            const Builder& on_update_current_timestamp() const
            {
                return attribute(dodbm::column_attribute::on_update_current_timestamp);
            }

            const Builder& unsigned_normal() const
            {
                return attribute(dodbm::column_attribute::unsigned_normal);
            }

            const Builder& unsigned_zerofill() const
            {
                return attribute(dodbm::column_attribute::unsigned_zerofill);
            }

        private:

            const Builder& attribute(dodbm::column_attribute attribute) const
            {
                base_t::m_operation->set_attribute(attribute);
                return *reinterpret_cast<const Builder*>(this);
            }
        };
    }
}