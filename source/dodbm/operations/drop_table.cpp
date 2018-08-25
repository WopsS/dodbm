#include <dodbm/stdafx.hpp>
#include <dodbm/operations/drop_table.hpp>

dodbm::operations::drop_table::drop_table(const std::string& name)
    : base_operation(operation_type::drop_table)
    , m_name(name)
{
}
