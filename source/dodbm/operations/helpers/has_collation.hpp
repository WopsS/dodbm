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

                has_collation() = default;

                void set_collation(collation value);
                const collation& get_collation() const;

            protected:

                virtual ~has_collation() = default;

            private:

                collation m_collation;
            };
        }
    }
}