#include <dodbm/command.hpp>

dodbm::command& dodbm::command::operator<<(const std::string& rhs)
{
    m_text += rhs;
    return *this;
}

dodbm::command& dodbm::command::operator<<(uint64_t rhs)
{
    m_text += std::to_string(rhs);
    return *this;
}

const std::string dodbm::command::get_text() const
{
    return m_text;
}
