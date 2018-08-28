#pragma once

#include <string>

namespace dodbm
{
    namespace operations
    {
        namespace helpers
        {
            class has_comment
            {
            public:

                has_comment() = default;

                void set_comment(const std::string& text);
                const std::string& get_comment() const;

            protected:

                virtual ~has_comment() = default;

            private:

                std::string m_comment;
            };
        }
    }
}