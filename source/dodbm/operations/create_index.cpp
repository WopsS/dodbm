#include <dodbm/operations/create_index.hpp>

dodbm::operation::type dodbm::operations::create_index::get_type() const
{
    return type::create_index;
}