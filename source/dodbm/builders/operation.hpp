#pragma once

#include <dodbm/operations/base_operation.hpp>

namespace dodbm
{
    namespace builders
    {
        template<typename T>
        class operation
        {
        public:

            static_assert(std::is_base_of<operations::base_operation, T>::value, "T should extend \"dodbm::operations::base_operation\"");

            operation(T* operation_ptr)
                : m_operation(operation_ptr)
            {
            }

        protected:

            virtual ~operation() = default;

            T* m_operation;
        };
    }
}