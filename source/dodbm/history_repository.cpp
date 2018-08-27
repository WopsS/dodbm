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

void dodbm::history_repository::get_insert_operation(const std::string& name)
{
}

void dodbm::history_repository::get_delete_operation(const std::string& name)
{
}
