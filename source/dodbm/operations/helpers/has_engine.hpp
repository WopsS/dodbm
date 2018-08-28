#pragma once

#include <dodbm/storage_engine.hpp>

namespace dodbm
{
    namespace operations
    {
        namespace helpers
        {
            class has_engine
            {
            public:

                has_engine() = default;

                void set_engine(storage_engine engine);
                const storage_engine& get_engine() const;

            protected:

                virtual ~has_engine() = default;

            private:

                storage_engine m_engine;
            };
        }
    }
}