#include <dodbm/operations/insert_data.hpp>

dodbm::operations::insert_data::insert_data(std::vector<db_data> data)
    : m_data(std::move(data))
{
}

dodbm::operation::type dodbm::operations::insert_data::get_type() const
{
    return type::insert_data;
}

const std::vector<dodbm::db_data>& dodbm::operations::insert_data::get_data() const
{
    return m_data;
}
