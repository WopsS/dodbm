#include <dodbm/command.hpp>

dodbm::command::command(bool allowed_in_prepared_statements)
    : m_allowed_in_prepared_statements(allowed_in_prepared_statements)
{
}

dodbm::command& dodbm::command::operator<<(char* rhs)
{
    m_text += rhs;
    return *this;
}

dodbm::command& dodbm::command::operator<<(const char* rhs)
{
    m_text += rhs;
    return *this;
}

dodbm::command& dodbm::command::operator<<(const std::string& rhs)
{
    m_text += rhs;
    return *this;
}

void dodbm::command::append_parameter(db_value value)
{
    m_paramters.emplace_back(value);
}

const std::vector<dodbm::db_value>& dodbm::command::get_parameters() const
{
    return m_paramters;
}

const std::string& dodbm::command::get_text() const
{
    return m_text;
}

bool dodbm::command::is_allowed_in_prepared_statements() const
{
    return m_allowed_in_prepared_statements;
}
