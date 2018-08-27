#include <dodbm/operations/drop_table.hpp>
#include <dodbm/exception.hpp>

dodbm::operations::drop_table::drop_table(const std::string& name)
    : m_name(name)
{
    if (name.empty())
    {
        throw dodbm::exception("Table name is empty");
    }
}

dodbm::operation::type dodbm::operations::drop_table::get_type() const
{
    return type::drop_table;
}

const std::string& dodbm::operations::drop_table::get_name() const
{
    return m_name;
}
