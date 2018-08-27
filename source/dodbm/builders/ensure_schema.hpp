#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/ensure_schema.hpp>

namespace dodbm
{
    namespace builders
    {
        class ensure_schema : public builders::operation<operations::ensure_schema>
        {
        public:

            using operation::operation;

            template<typename T>
            const ensure_schema& collation() const
            {
                m_operation->set_collation(std::unique_ptr<dodbm::collation>(new dodbm::collation(T::name, T::charset)));
                return *this;
            }
        };
    }
}