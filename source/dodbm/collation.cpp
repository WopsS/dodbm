#include <dodbm/collation.hpp>

dodbm::collation::collation(const std::string& name, const std::string& charset)
    : m_name(name)
    , m_charset(charset)
{
}

dodbm::collation::operator const std::string() const
{
    return m_name;
}

bool dodbm::collation::empty() const
{
    return m_name.empty();
}

const std::string& dodbm::collation::get_charset() const
{
    return m_charset;
}
