#include <dodbm/dodbm.hpp>
#include <dodbm/migrations.hpp>

dodbm::migrations::migrations(const providers::base_provider& provider)
    : m_provider(provider)
{
}

void dodbm::migrations::run()
{
}
