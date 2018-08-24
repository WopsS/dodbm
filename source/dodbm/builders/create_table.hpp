#pragma once

#include <dodbm/operations/create_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class create_table : public operation<operations::create_table>
        {
        public:

            using operation::operation;

            template<typename T>
            const create_table& engine() const
            {
                m_operation->set_engine(T::name);
                return *this;
            }

            template<typename T>
            const create_table& collation() const
            {
                m_operation->set_collation(T::name);
                return *this;
            }

            const create_table& columns(std::function<void()> func) const;

            const create_table& constraints(std::function<void()> func) const;

            const create_table& comment(const std::string& text) const;
        };
    }
}