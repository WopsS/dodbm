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

void dodbm::operations::create_table::set_primary_key(std::shared_ptr<add_primary_key> primary_key)
{
    m_primary_key = primary_key;
}

const std::shared_ptr<dodbm::operations::add_primary_key> dodbm::operations::create_table::get_primary_key() const
{
    return m_primary_key;
}

void dodbm::operations::create_table::set_foreign_keys(std::vector<std::shared_ptr<add_foreign_key>> foreign_keys)
{
    m_foreign_keys = std::move(foreign_keys);
}

const std::vector<std::shared_ptr<dodbm::operations::add_foreign_key>>& dodbm::operations::create_table::get_foreign_keys() const
{
    return m_foreign_keys;
}

void dodbm::operations::create_table::set_unique_constraints(std::vector<std::shared_ptr<add_unique_constraint>> unique_constraints)
{
    m_unique_constraints = std::move(unique_constraints);
}

const std::vector<std::shared_ptr<dodbm::operations::add_unique_constraint>>& dodbm::operations::create_table::get_unique_constraints() const
{
    return m_unique_constraints;
}
