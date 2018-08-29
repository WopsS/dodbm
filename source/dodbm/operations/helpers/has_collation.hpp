#pragma once

#include <dodbm/collation.hpp>

namespace dodbm
{
    namespace operations
    {
        namespace helpers
        {
            class has_collation
            {
            public:

                void set_collation(collation value);
                const collation& get_collation() const;

            protected:

                has_collation() = default;
                virtual ~has_collation() = default;

            private:

                collation m_collation;
            };
        }
    }
}