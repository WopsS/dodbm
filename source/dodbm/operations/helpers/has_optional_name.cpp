#include <dodbm/operations/helpers/has_optional_name.hpp>

dodbm::operations::helpers::has_optional_name::has_optional_name(const std::string& name)
    : m_name(name)
{
}

const std::string& dodbm::operations::helpers::has_optional_name::get_name() const
{
    return m_name;
}
