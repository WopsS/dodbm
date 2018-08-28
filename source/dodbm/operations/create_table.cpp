#include <dodbm/operations/create_table.hpp>

dodbm::operation::type dodbm::operations::create_table::get_type() const
{
    return type::create_table;
}
