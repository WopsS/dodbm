#include <dodbm/operations/helpers/has_required_name.hpp>
#include <dodbm/exception.hpp>

dodbm::operations::helpers::has_required_name::has_required_name(const std::string& name)
    : m_name(name)
{
    if (name.empty())
    {
        throw dodbm::exception("Operation requires a valid name");
    }
}

const std::string& dodbm::operations::helpers::has_required_name::get_name() const
{
    return m_name;
}
