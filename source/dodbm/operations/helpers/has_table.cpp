#include <dodbm/operations/helpers/has_table.hpp>
#include <dodbm/exception.hpp>

void dodbm::operations::helpers::has_table::set_table(const std::string& name)
{
    m_table = name;
}

const std::string& dodbm::operations::helpers::has_table::get_table() const
{
    if (m_table.empty())
    {
        throw dodbm::exception("Operation require a table");
    }

    return m_table;
}
