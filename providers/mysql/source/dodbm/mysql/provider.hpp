#pragma once

#include <dodbm/mysql/config.hpp>
#include <dodbm/provider.hpp>

namespace dodbm
{
    namespace mysql
    {
        class provider : public dodbm::provider
        {
        public:

            provider(const config& config);
            ~provider();
        };
    }
}