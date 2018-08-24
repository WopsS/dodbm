#pragma once

#include <dodbm/operations/alter_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class alter_table : public operation<operations::alter_table>
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
                m_operation->set_collation(T::name);
                return *this;
            }

            const alter_table& comment(const std::string& text) const;
        };
    }
}