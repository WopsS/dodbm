#include <dodbm/builders/create_table.hpp>

const dodbm::builders::create_table& dodbm::builders::create_table::columns(std::function<void(columns_builder&)> func)
{
    columns_builder builder;
    func(builder);

    m_operation->set_columns(std::move(builder.columns));

    return *this;
}

const dodbm::builders::create_table& dodbm::builders::create_table::constraints(std::function<void(constraints_builder)> func) const
{
    constraints_builder builder;
    func(builder);

    m_operation->set_primary_key(std::move(builder.primary_key_));
    m_operation->set_foreign_keys(std::move(builder.foreign_keys));
    m_operation->set_unique_constraints(std::move(builder.unique_constraints));

    return *this;
}
