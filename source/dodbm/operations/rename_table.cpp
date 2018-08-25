#include <dodbm/stdafx.hpp>
#include <dodbm/operations/rename_table.hpp>

dodbm::operations::rename_table::rename_table(const std::string& name)
    : base_operation(operation_type::rename_table)
    , m_name(name)
{
}

void dodbm::operations::rename_table::set_new_name(const std::string& name)
{
    m_new_name = name;
}
