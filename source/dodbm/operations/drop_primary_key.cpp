#include <dodbm/operations/drop_primary_key.hpp>

dodbm::operation::type dodbm::operations::drop_primary_key::get_type() const
{
    return type::drop_primary_key;
}

