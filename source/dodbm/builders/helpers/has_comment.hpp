#pragma once

#include <string>

namespace dodbm
{
    namespace builders
    {
        namespace helpers
        {
            template<typename T>
            class has_comment
            {
            public:

                has_comment() = default;

                const T& comment(const std::string& text) const
                {
                    auto ptr = static_cast<const T*>(this);
                    ptr->get_operation()->set_comment(text);

                    return *ptr;
                }

            protected:

                virtual ~has_comment() = default;
            };
        }
    }
}