#pragma once

#include <string>
#include <vector>

namespace dodbm
{
    namespace operations
    {
        namespace helpers
        {
            class has_columns
            {
            public:

                void set_columns(std::vector<std::string> columns);
                const std::vector<std::string>& get_columns() const;

            protected:

                has_columns() = default;
                virtual ~has_columns() = default;

            private:

                std::vector<std::string> m_columns;
            };
        }
    }
}