#pragma once

#include <string>

namespace dodbm
{
    namespace operations
    {
        namespace helpers
        {
            class has_column
            {
            public:

                void set_column(const std::string& name);
                const std::string& get_column() const;

            protected:

                has_column() = default;
                virtual ~has_column() = default;

            private:

                std::string m_column;
            };
        }
    }
}