#pragma once

#include <string>

namespace dodbm
{
    namespace operations
    {
        namespace helpers
        {
            class has_schema
            {
            public:

                void set_schema(const std::string& name);
                const std::string& get_schema() const;

            protected:

                has_schema() = default;
                virtual ~has_schema() = default;

            private:

                std::string m_schema;
            };
        }
    }
}