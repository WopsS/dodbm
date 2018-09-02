#include <dodbm/operations/drop_index.hpp>

dodbm::operation::type dodbm::operations::drop_index::get_type() const
{
    return type::drop_index;
}