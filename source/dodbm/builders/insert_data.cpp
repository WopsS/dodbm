#include <dodbm/builders/insert_data.hpp>

const dodbm::builders::insert_data& dodbm::builders::insert_data::in(const std::string& table_name) const
{
    m_operation->set_table(table_name);
    return *this;
}