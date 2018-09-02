#include <dodbm/builders/delete_data.hpp>

const dodbm::builders::delete_data& dodbm::builders::delete_data::from(const std::string& table_name) const
{
    m_operation->set_table(table_name);
    return *this;
}