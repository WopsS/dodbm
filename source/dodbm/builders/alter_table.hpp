#pragma once

#include <string>

#include <dodbm/collation.hpp>

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/alter_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class alter_table : public builders::operation<operations::alter_table>
        {
        public:

            using operation::operation;

            template<typename T>
            const alter_table& engine() const
            {
                m_operation->set_engine(T::name);
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