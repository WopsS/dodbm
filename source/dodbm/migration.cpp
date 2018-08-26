#include <dodbm/migration.hpp>

std::queue<dodbm::operation> dodbm::migration::get_up_operations()
{
    migration_builder builder;
    up(builder);

    return builder.get_operations();
}

std::queue<dodbm::operation> dodbm::migration::get_down_operations()
{
    migration_builder builder;
    down(builder);

    return builder.get_operations();
}