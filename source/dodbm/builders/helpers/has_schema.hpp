#pragma once

#include <string>

namespace dodbm
{
    namespace builders
    {
        namespace helpers
        {
            template<typename T>
            class has_schema
            {
            public:

                has_schema() = default;

                const T& schema(const std::string& name) const
                {
                    auto ptr = static_cast<const T*>(this);
                    ptr->get_operation()->set_schema(name);

                    return *ptr;
                }

            protected:

                virtual ~has_schema() = default;
            };
        }
    }
}