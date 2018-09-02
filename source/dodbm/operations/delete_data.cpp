#include <dodbm/operations/delete_data.hpp>

dodbm::operation::type dodbm::operations::delete_data::get_type() const
{
    return type::delete_data;
}
