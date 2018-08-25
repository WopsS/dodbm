#include <dodbm/stdafx.hpp>
#include <dodbm/operations/create_table.hpp>

dodbm::operations::create_table::create_table(const std::string& name)
    : base_operation(operation_type::create_table)
    , m_name(name)
{
}

void dodbm::operations::create_table::set_engine(const std::string& name)
{
    m_engine = name;
}

void dodbm::operations::create_table::set_collation(const std::string& name)
{
    m_collation = name;
}

void dodbm::operations::create_table::set_columns(std::function<void()> func)
{
    m_columns = func;
}

void dodbm::operations::create_table::set_constraints(std::function<void()> func)
{
    m_constraints = func;
}

void dodbm::operations::create_table::set_comment(const std::string& text)
{
    m_comment = text;
}
