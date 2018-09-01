#include <dodbm/operations/drop_column.hpp>

dodbm::operation::type dodbm::operations::drop_column::get_type() const
{
    return type::drop_column;
}
