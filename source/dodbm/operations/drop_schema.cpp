#include <dodbm/operations/drop_schema.hpp>

dodbm::operation::type dodbm::operations::drop_schema::get_type() const
{
    return type::drop_schema;
}
