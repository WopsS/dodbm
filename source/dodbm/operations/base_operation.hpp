#pragma once

namespace dodbm
{
    namespace operations
    {
        class base_operation
        {
        public:

            base_operation() = default;
            virtual ~base_operation() = default;

            virtual const std::string compile() const = 0;
        };
    }
}