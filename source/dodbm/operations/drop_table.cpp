#include <dodbm/operations/drop_table.hpp>

dodbm::operation::type dodbm::operations::drop_table::get_type() const
{
    return type::drop_table;
}
