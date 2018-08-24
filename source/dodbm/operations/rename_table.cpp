#include <dodbm/dodbm.hpp>
#include <dodbm/operations/rename_table.hpp>

dodbm::operations::rename_table::rename_table(const std::string& name)
    : m_name(name)
{
}

const std::string dodbm::operations::rename_table::compile() const
{
    return std::string();
}

void dodbm::operations::rename_table::set_new_name(const std::string& name)
{
    m_new_name = name;
}
