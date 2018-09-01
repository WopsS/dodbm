#pragma once

#include <string>

namespace dodbm
{
    namespace builders
    {
        namespace helpers
        {
            template<typename T>
            class has_table
            {
            public:

                const T& table(const std::string& name) const
                {
                    auto ptr = static_cast<const T*>(this);
                    ptr->get_operation()->set_table(name);

                    return *ptr;
                }

            protected:

                has_table() = default;
                virtual ~has_table() = default;
            };
        }
    }
}