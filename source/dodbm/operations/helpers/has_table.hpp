#pragma once

#include <string>

namespace dodbm
{
    namespace operations
    {
        namespace helpers
        {
            class has_table
            {
            public:

                void set_table(const std::string& name);
                const std::string& get_table() const;

            protected:

                has_table() = default;
                virtual ~has_table() = default;

            private:

                std::string m_table;
            };
        }
    }
}