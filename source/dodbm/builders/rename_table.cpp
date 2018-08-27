#include <dodbm/builders/rename_table.hpp>

const dodbm::builders::rename_table& dodbm::builders::rename_table::to(const std::string& name) const
{
    m_operation->set_new_name(name);
    return *this;
}