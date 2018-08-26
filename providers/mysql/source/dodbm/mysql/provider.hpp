#pragma once

#include <functional>
#include <string>

#include <dodbm/mysql/config.hpp>
#include <dodbm/base_provider.hpp>

namespace dodbm
{
    namespace mysql
    {
        class provider : public base_provider
        {
        public:

            provider(const config& config);
            ~provider();
        };
    }
}