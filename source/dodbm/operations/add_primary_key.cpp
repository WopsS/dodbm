#include <dodbm/operations/add_primary_key.hpp>

dodbm::operation::type dodbm::operations::add_primary_key::get_type() const
{
    return type::add_primary_key;
}

