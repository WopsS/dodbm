#pragma once

#include <dodbm/storage_engine.hpp>

namespace dodbm
{
    namespace builders
    {
        namespace helpers
        {
            template<typename T>
            class has_engine
            {
            public:

                has_engine() = default;

                template<typename Engine>
                const T& engine() const
                {
                    auto ptr = static_cast<const T*>(this);
                    ptr->get_operation()->set_engine(dodbm::storage_engine(Engine::name));

                    return *ptr;
                }

            protected:

                virtual ~has_engine() = default;
            };
        }
    }
}