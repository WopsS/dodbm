#include <dodbm/operations/update_data.hpp>

dodbm::operation::type dodbm::operations::update_data::get_type() const
{
    return type::update_data;
}

void dodbm::operations::update_data::set_data(std::vector<db_data> data)
{
    m_data = std::move(data);
}

const std::vector<dodbm::db_data>& dodbm::operations::update_data::get_data() const
{
    return m_data;
}
