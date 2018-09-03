#include <dodbm/collation.hpp>
#include <dodbm/exception.hpp>

std::string dodbm::collation::m_default_name;
std::string dodbm::collation::m_default_charset;

dodbm::collation::collation()
    : m_name(m_default_name)
    , m_charset(m_default_charset)
{
}

dodbm::collation::collation(const std::string& name, const std::string& charset)
    : m_name(name)
    , m_charset(charset)
{
    if (m_name.empty())
    {
        throw dodbm::exception("A collation requires a valid name");
    }

    if (m_charset.empty())
    {
        throw dodbm::exception("A collation requires a valid charset");
    }
}

void dodbm::collation::set_default(const std::string& name, const std::string& charset)
{
    m_default_name = name;
    m_default_charset = charset;
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
