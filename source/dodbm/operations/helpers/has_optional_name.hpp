#pragma once

#include <string>

namespace dodbm
{
    namespace operations
    {
        namespace helpers
        {
            class has_optional_name
            {
            public:

                has_optional_name(const std::string& name);

                const std::string& get_name() const;

            protected:

                virtual ~has_optional_name() = default;

            private:

                std::string m_name;
            };
        }
    }
}