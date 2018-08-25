#pragma once

#include <dodbm/operations/operation_type.hpp>

namespace dodbm
{
    namespace operations
    {
        class base_operation
        {
        public:

            base_operation(operation_type type);
            virtual ~base_operation() = default;

            operation_type get_type();

        private:

            operation_type m_type;
        };
    }
}