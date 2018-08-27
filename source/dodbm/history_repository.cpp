#include <dodbm/history_repository.hpp>

bool dodbm::history_repository::exists() const
{
    return false;
}

void dodbm::history_repository::create()
{
}

const std::string dodbm::history_repository::get_last_applied_migration() const
{
    return std::string();
}

void dodbm::history_repository::insert_migration(const std::string& name)
{
}

void dodbm::history_repository::delete_migration(const std::string& name)
{
}
