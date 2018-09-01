#pragma once

#include <string>

namespace dodbm
{
    namespace builders
    {
        namespace helpers
        {
            template<typename T>
            class has_new_name
            {
            public:

                const T& to(const std::string& new_name) const
                {
                    auto ptr = static_cast<const T*>(this);
                    ptr->get_operation()->set_new_name(new_name);

                    return *ptr;
                }

            protected:

                has_new_name() = default;
                virtual ~has_new_name() = default;
            };
        }
    }
}