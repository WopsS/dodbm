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

                void set_comment(const std::string& text);
                const std::string& get_comment() const;

            protected:

                has_comment() = default;
                virtual ~has_comment() = default;

            private:

                std::string m_comment;
            };
        }
    }
}