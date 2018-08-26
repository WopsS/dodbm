#include <dodbm/provider.hpp>

const dodbm::sql_generator dodbm::provider::get_generator() const
{
    return sql_generator();
}
