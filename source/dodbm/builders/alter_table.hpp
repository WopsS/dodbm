#pragma once

#include <dodbm/collation.hpp>
#include <dodbm/storage_engine.hpp>

#include <dodbm/builders/operation_with_schema.hpp>
#include <dodbm/operations/alter_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class alter_table : public builders::operation_with_schema<alter_table, operations::alter_table>
        {
        public:

            using operation_with_schema::operation_with_schema;

            template<typename T>
            const alter_table& engine() const
            {
                m_operation->set_engine(std::unique_ptr<dodbm::storage_engine>(new storage_engine(T::name)));
                return *this;
            }

            template<typename T>
            const alter_table& collation() const
            {
                m_operation->set_collation(dodbm::collation(T::name, T::charset));
                return *this;
            }

            const alter_table& comment(const std::string& text) const;
        };
    }
}