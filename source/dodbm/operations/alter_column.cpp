#include <dodbm/operations/alter_column.hpp>

dodbm::operation::type dodbm::operations::alter_column::get_type() const
{
    return type::alter_column;
}
