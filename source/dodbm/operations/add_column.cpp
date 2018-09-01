#include <dodbm/operations/add_column.hpp>

dodbm::operation::type dodbm::operations::add_column::get_type() const
{
    return type::add_column;
}
