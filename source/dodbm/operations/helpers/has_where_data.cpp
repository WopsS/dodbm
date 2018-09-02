#include <dodbm/operations/helpers/has_where_data.hpp>

void dodbm::operations::helpers::has_where_data::set_where_data(std::vector<db_data> data)
{
    m_where_data = std::move(data);
}

const std::vector<dodbm::db_data>& dodbm::operations::helpers::has_where_data::get_where_data() const
{
    return m_where_data;
}
