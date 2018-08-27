#pragma once

#include <memory>
#include <type_traits>

#include <dodbm/operation.hpp>

namespace dodbm
{
    namespace builders
    {
        template<typename T>
        class operation
        {
        public:

            static_assert(std::is_base_of<dodbm::operation, T>::value, "T should extend \"dodbm::operation\"");

            operation(std::shared_ptr<T> operation)
                : m_operation(operation)
            {
            }

        protected:

            virtual ~operation() = default;

            std::shared_ptr<T> m_operation;
        };
    }
}