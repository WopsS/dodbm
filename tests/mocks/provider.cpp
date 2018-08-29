#include <mocks/provider.hpp>

mocks::provider::provider()
    : m_connection(new connection())
{
}

dodbm::connection* mocks::provider::get_connection() const
{
    return m_connection.get();
}
