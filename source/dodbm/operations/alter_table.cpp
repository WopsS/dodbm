#include <dodbm/stdafx.hpp>
#include <dodbm/operations/alter_table.hpp>

dodbm::operations::alter_table::alter_table(const std::string& name)
    : base_operation(operation_type::alter_table)
    , m_name(name)
{
}

void dodbm::operations::alter_table::set_engine(const std::string& name)
{
    m_engine = name;
}

void dodbm::operations::alter_table::set_collation(const std::string& name)
{
    m_collation = name;
}

void dodbm::operations::alter_table::set_comment(const std::string& text)
{
    m_comment = text;
}
