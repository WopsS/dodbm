#include <dodbm/operations/rename_table.hpp>
#include <dodbm/exception.hpp>

dodbm::operation::type dodbm::operations::rename_table::get_type() const
{
    return type::rename_table;
}

