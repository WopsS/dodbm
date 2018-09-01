#include <dodbm/operations/rename_column.hpp>

dodbm::operation::type dodbm::operations::rename_column::get_type() const
{
    return type::rename_column;
}
