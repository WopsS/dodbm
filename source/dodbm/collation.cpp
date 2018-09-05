#include <dodbm/collation.hpp>
#include <dodbm/exception.hpp>

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
