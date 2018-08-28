#pragma once

#include <dodbm/collation.hpp>

namespace dodbm
{
    namespace builders
    {
        namespace helpers
        {
            template<typename T>
            class has_collation
            {
            public:

                has_collation() = default;

                template<typename Collation>
                const T& collation() const
                {
                    auto ptr = static_cast<const T*>(this);
                    ptr->get_operation()->set_collation(dodbm::collation(Collation::name, Collation::charset));

                    return *ptr;
                }

            protected:

                virtual ~has_collation() = default;
            };
        }
    }
}