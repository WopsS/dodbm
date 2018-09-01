#include <dodbm/operations/create_table.hpp>

dodbm::operation::type dodbm::operations::create_table::get_type() const
{
    return type::create_table;
}

void dodbm::operations::create_table::set_columns(std::vector<std::shared_ptr<add_column>> columns)
{
    m_columns = std::move(columns);
}

const std::vector<std::shared_ptr<dodbm::operations::add_column>>& dodbm::operations::create_table::get_columns() const
{
    return m_columns;
}
