#include <dodbm/dodbm.hpp>
#include <dodbm/operations/alter_table.hpp>
#include "..\builders\alter_table.hpp"

dodbm::operations::alter_table::alter_table(const std::string& name)
    : m_name(name)
{
}

const std::string dodbm::operations::alter_table::compile() const
{
    return std::string();
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
