#include <dodbm/dodbm.hpp>
#include <dodbm/operations/create_table.hpp>

dodbm::operations::create_table::create_table(const std::string& name)
    : m_name(name)
{
}

const std::string dodbm::operations::create_table::compile() const
{
    return std::string();
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
