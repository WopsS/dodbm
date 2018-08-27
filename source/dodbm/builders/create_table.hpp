#pragma once

#include <functional>

#include <dodbm/collation.hpp>
#include <dodbm/storage_engine.hpp>

#include <dodbm/builders/operation_with_schema.hpp>
#include <dodbm/operations/create_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class create_table : public builders::operation_with_schema<create_table, operations::create_table>
        {
        public:

            using operation_with_schema::operation_with_schema;

            template<typename T>
            const create_table& engine() const
            {
                m_operation->set_engine(dodbm::storage_engine(T::name, T::charset));
                return *this;
            }

            template<typename T>
            const create_table& collation() const
            {
                m_operation->set_collation(dodbm::collation(T::name, T::charset));
                return *this;
            }

            const create_table& columns(std::function<void()> func);

            const create_table& constraints(std::function<void()> func) const;

            const create_table& comment(const std::string& text) const;
        };
    }
}