#include <dodbm/migration.hpp>

std::queue<std::shared_ptr<dodbm::operation>> dodbm::migration::get_up_operations()
{
    migration_builder builder;
    up(builder);

    return builder.operations;
}

std::queue<std::shared_ptr<dodbm::operation>> dodbm::migration::get_down_operations()
{
    migration_builder builder;
    down(builder);

    return builder.operations;
}