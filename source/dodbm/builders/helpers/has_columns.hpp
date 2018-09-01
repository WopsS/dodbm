#pragma once

#include <initializer_list>
#include <string>

namespace dodbm
{
    namespace builders
    {
        namespace helpers
        {
            template<typename T>
            class has_columns
            {
            public:

                const T& column(const std::string& name) const
                {
                    return columns({ name });
                }

                const T& columns(std::initializer_list<std::string> columns) const
                {
                    auto ptr = static_cast<const T*>(this);
                    ptr->get_operation()->set_columns(columns);

                    return *ptr;
                }

            protected:

                has_columns() = default;
                virtual ~has_columns() = default;
            };
        }
    }
}