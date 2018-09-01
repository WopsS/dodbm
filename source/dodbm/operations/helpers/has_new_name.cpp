#include <dodbm/operations/helpers/has_new_name.hpp>
#include <dodbm/exception.hpp>

void dodbm::operations::helpers::has_new_name::set_new_name(const std::string& new_name)
{
    if (new_name.empty())
    {
        throw dodbm::exception("Operation requires a valid new name");
    }

    m_new_name = new_name;
}

const std::string& dodbm::operations::helpers::has_new_name::get_new_name() const
{
    return m_new_name;
}
