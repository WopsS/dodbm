#pragma once

#include <dodbm/provider.hpp>

#include <mocks/connection.hpp>

namespace mocks
{
    class provider : public dodbm::provider
    {
    public:

        provider();

        dodbm::connection* get_connection() const final;

    private:

        std::unique_ptr<connection> m_connection;
    };
}