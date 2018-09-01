#pragma once

#include <string>

namespace dodbm
{
    namespace operations
    {
        namespace helpers
        {
            class has_required_name
            {
            public:

                has_required_name(const std::string& name);

                const std::string& get_name() const;

            protected:

                virtual ~has_required_name() = default;

            private:

                std::string m_name;
            };
        }
    }
}