#include <dodbm/storage_engine.hpp>
#include <dodbm/exception.hpp>

dodbm::storage_engine::storage_engine(const std::string& name)
    : m_name(name)
{
    if (m_name.empty())
    {
        throw dodbm::exception("A storage engine requires a valid name");
    }
}

dodbm::storage_engine::operator const std::string() const
{
    return m_name;
}

bool dodbm::storage_engine::empty() const
{
    return m_name.empty();
}
