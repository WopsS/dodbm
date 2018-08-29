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

                void set_engine(storage_engine engine);
                const storage_engine& get_engine() const;

            protected:

                has_engine() = default;
                virtual ~has_engine() = default;

            private:

                storage_engine m_engine;
            };
        }
    }
}