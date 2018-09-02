#include <dodbm/builders/update_data.hpp>

const dodbm::builders::update_data& dodbm::builders::update_data::set(std::initializer_list<db_data> data) const
{
    m_operation->set_data(data);
    return *this;
}
