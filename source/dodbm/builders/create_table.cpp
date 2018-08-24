#include <dodbm/dodbm.hpp>
#include <dodbm/builders/create_table.hpp>

const dodbm::builders::create_table& dodbm::builders::create_table::columns(std::function<void()> func) const
{
    m_operation->set_columns(func);
    return *this;
}

const dodbm::builders::create_table& dodbm::builders::create_table::constraints(std::function<void()> func) const
{
    m_operation->set_constraints(func);
    return *this;
}

const dodbm::builders::create_table& dodbm::builders::create_table::comment(const std::string& text) const
{
    m_operation->set_comment(text);
    return *this;
}
