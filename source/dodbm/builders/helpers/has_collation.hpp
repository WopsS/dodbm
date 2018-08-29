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

                template<typename Collation>
                const T& collation() const
                {
                    auto ptr = static_cast<const T*>(this);
                    ptr->get_operation()->set_collation(dodbm::collation(Collation::name, Collation::charset));

                    return *ptr;
                }

            protected:

                has_collation() = default;
                virtual ~has_collation() = default;
            };
        }
    }
}