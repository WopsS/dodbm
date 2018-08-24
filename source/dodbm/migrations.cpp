#include <dodbm/dodbm.hpp>
#include <dodbm/migrations.hpp>

dodbm::migrations::migrations(const base_provider& provider)
    : m_provider(provider)
{
}

void dodbm::migrations::run()
{
}
