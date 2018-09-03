#include <dodbm/mysql/provider.hpp>

dodbm::mysql::provider::provider(const config& config)
    : m_connection(new mysql::connection(config))
{
}

dodbm::connection* dodbm::mysql::provider::get_connection() const
{
    return m_connection.get();
}
