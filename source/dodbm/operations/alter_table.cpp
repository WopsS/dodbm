#include <dodbm/operations/alter_table.hpp>

dodbm::operation::type dodbm::operations::alter_table::get_type() const
{
    return type::alter_table;
}
