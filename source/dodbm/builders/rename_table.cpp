#include <dodbm/dodbm.hpp>
#include <dodbm/builders/rename_table.hpp>

void dodbm::builders::rename_table::to(const std::string& name) const
{
    m_operation->set_new_name(name);
}