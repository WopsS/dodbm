#include <dodbm/operations/helpers/has_columns.hpp>
#include <dodbm/exception.hpp>

void dodbm::operations::helpers::has_columns::set_columns(std::vector<std::string> columns)
{
    if (columns.empty())
    {
        throw dodbm::exception("Operation requires a valid columns array");
    }

    m_columns = std::move(columns);
}

const std::vector<std::string>& dodbm::operations::helpers::has_columns::get_columns() const
{
    return m_columns;
}
