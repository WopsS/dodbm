#pragma once

#include <string>

namespace dodbm
{
    namespace operations
    {
        namespace helpers
        {
            class has_new_name
            {
            public:

                void set_new_name(const std::string& new_name);
                const std::string& get_new_name() const;

            protected:

                has_new_name() = default;
                virtual ~has_new_name() = default;

            private:

                std::string m_new_name;
            };
        }
    }
}