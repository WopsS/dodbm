#include <dodbm/provider.hpp>

const dodbm::history_repository dodbm::provider::get_history_repository() const
{
    return history_repository();
}

const dodbm::sql_generator dodbm::provider::get_sql_generator() const
{
    return sql_generator();
}

const dodbm::sql_generator_helper dodbm::provider::get_sql_generator_helper() const
{
    return sql_generator_helper();
}
