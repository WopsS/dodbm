#pragma once

#include <string>

#include <dodbm/builders/operation.hpp>
#include <dodbm/operation_with_schema.hpp>

namespace dodbm
{
    namespace builders
    {
        template<typename T, typename Operation>
        class operation_with_schema : public builders::operation<Operation>
        {
        public:

            static_assert(std::is_base_of<dodbm::operation_with_schema, Operation>::value, "Operation should extend \"dodbm::operation_with_schema\"");

            using base_t = builders::operation<Operation>;

            using base_t::operation;

            const T& schema(const std::string& name)
            {
                base_t::m_operation->set_schema(name);
                return *reinterpret_cast<T*>(this);
            }

        protected:

            virtual ~operation_with_schema() = default;
        };
    }
}