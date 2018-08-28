#include <dodbm/operations/ensure_schema.hpp>

dodbm::operation::type dodbm::operations::ensure_schema::get_type() const
{
    return type::ensure_schema;
}
