#pragma once

#include <string>

namespace dodbm
{
    namespace builders
    {
        namespace helpers
        {
            template<typename T>
            class has_column
            {
            public:

                const T& column(const std::string& name) const
                {
                    auto ptr = static_cast<const T*>(this);
                    ptr->get_operation()->set_column(name);

                    return *ptr;
                }

            protected:

                has_column() = default;
                virtual ~has_column() = default;
            };
        }
    }
}