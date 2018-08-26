#include <dodbm/command.hpp>

dodbm::command& dodbm::command::operator<<(const std::string& rhs)
{
    m_text += rhs;
    return *this;
}
