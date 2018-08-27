#include <dodbm/builders/rename_table.hpp>

void dodbm::builders::rename_table::to(const std::string& name)
{
    m_operation->set_new_name(name);
}