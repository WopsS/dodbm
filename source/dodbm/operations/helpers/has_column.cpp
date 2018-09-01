#include <dodbm/operations/helpers/has_column.hpp>
#include <dodbm/exception.hpp>

void dodbm::operations::helpers::has_column::set_column(const std::string& name)
{
    if (name.empty())
    {
        throw dodbm::exception("Operation requires a valid column");
    }

    m_column = name;
}

const std::string& dodbm::operations::helpers::has_column::get_column() const
{
    return m_column;
}
