#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/alter_database.hpp>

namespace dodbm
{
    namespace builders
    {
        class alter_database : public builders::operation<operations::alter_database>
        {
        public:

            using operation::operation;

            template<typename T>
            const alter_database& collation() const
            {
                m_operation->set_collation(std::unique_ptr<dodbm::collation>(new dodbm::collation(T::name, T::charset)));
                return *this;
            }
        };
    }
}