#include <dodbm/dodbm.hpp>
#include <dodbm/operations/drop_table.hpp>

dodbm::operations::drop_table::drop_table(const std::string& name)
    : m_name(name)
{
}

const std::string dodbm::operations::drop_table::compile() const
{
    return std::string();
}
