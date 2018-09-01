#include <dodbm/operations/add_foreign_key.hpp>

dodbm::operations::add_foreign_key::add_foreign_key(const std::string& name)
    : has_optional_name(name)
    , m_on_delete(action::restrict)
    , m_on_update(action::restrict)
{
}

dodbm::operation::type dodbm::operations::add_foreign_key::get_type() const
{
    return type::add_foreign_key;
}

void dodbm::operations::add_foreign_key::set_on_column(const std::string& name)
{
    m_on_column = name;
}

const std::string& dodbm::operations::add_foreign_key::get_on_column() const
{
    return m_on_column;
}

void dodbm::operations::add_foreign_key::set_from_table(const std::string& name)
{
    m_from_table = name;
}

const std::string& dodbm::operations::add_foreign_key::get_from_table() const
{
    return m_from_table;
}

void dodbm::operations::add_foreign_key::set_in_schema(const std::string& name)
{
    m_in_schema = name;
}

const std::string& dodbm::operations::add_foreign_key::get_in_schema() const
{
    return m_in_schema;
}

void dodbm::operations::add_foreign_key::set_on_delete(action action)
{
    m_on_delete = action;
}

const std::string dodbm::operations::add_foreign_key::get_on_delete() const
{
    return get_action_string(m_on_delete);
}

void dodbm::operations::add_foreign_key::set_on_update(action action)
{
    m_on_update = action;
}

const std::string dodbm::operations::add_foreign_key::get_on_update() const
{
    return get_action_string(m_on_update);
}

const std::string dodbm::operations::add_foreign_key::get_action_string(action act) const
{
    switch (act)
    {
        case action::cascade:
        {
            return "CASCADE";
        }
        case action::no_action:
        {
            return "NO ACTION";
        }
        case action::restrict:
        {
            return "RESTRICT";
        }
        case action::set_null:
        {
            return "SET NULL";
        }
    }

    return "";
}
