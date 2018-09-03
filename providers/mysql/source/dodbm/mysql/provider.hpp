#pragma once

#include <memory>

#include <dodbm/provider.hpp>

#include <dodbm/mysql/connection.hpp>

namespace dodbm
{
    namespace mysql
    {
        class provider : public dodbm::provider
        {
        public:

            provider(const config& config);
            ~provider() = default;

            dodbm::connection* get_connection() const final;

        private:

            std::unique_ptr<mysql::connection> m_connection;
        };
    }
}