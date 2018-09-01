#include <dodbm/builders/create_table.hpp>

const dodbm::builders::create_table& dodbm::builders::create_table::columns(std::function<void(columns_builder&)> func)
{
    columns_builder builder;
    func(builder);

    m_operation->set_columns(std::move(builder.columns));

    return *this;
}

const dodbm::builders::create_table& dodbm::builders::create_table::constraints(std::function<void()> func) const
{
    func();
    return *this;
}
