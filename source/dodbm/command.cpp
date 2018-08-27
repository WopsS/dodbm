#include <dodbm/command.hpp>

dodbm::command& dodbm::command::operator<<(const std::string& rhs)
{
    m_text += rhs;
    return *this;
}

const std::string dodbm::command::get_text() const
{
    return m_text;
}
