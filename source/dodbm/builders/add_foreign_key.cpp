#include <dodbm/builders/add_foreign_key.hpp>

const dodbm::builders::add_foreign_key& dodbm::builders::add_foreign_key::on_column(const std::string& name) const
{
    m_operation->set_on_column(name);
    return *this;
}

const dodbm::builders::add_foreign_key& dodbm::builders::add_foreign_key::from_table(const std::string& name) const
{
    m_operation->set_from_table(name);
    return *this;
}

const dodbm::builders::add_foreign_key& dodbm::builders::add_foreign_key::in_schema(const std::string& name) const
{
    m_operation->set_in_schema(name);
    return *this;
}
