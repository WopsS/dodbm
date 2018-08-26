#include <dodbm/repository.hpp>

dodbm::repository::repository(std::unique_ptr<provider> provider)
    : m_provider(std::move(provider))
{
}

void dodbm::repository::migrate()
{
}

void dodbm::repository::rollback_to(const std::string& name)
{
}
