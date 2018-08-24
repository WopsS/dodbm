#include <dodbm/stdafx.hpp>
#include <dodbm/repository.hpp>

dodbm::repository::repository(std::shared_ptr<base_provider> provider)
    : m_provider(provider)
{
}

void dodbm::repository::run()
{
    for (auto& i : m_migrations)
    {
        auto migration = i.second.get();

        migration_builder builder;
        migration->build(builder);
    }
}
