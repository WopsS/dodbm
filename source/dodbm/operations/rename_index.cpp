#include <dodbm/operations/rename_index.hpp>

dodbm::operation::type dodbm::operations::rename_index::get_type() const
{
    return type::rename_index;
}