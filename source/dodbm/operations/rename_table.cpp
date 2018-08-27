#include <dodbm/operations/rename_table.hpp>
#include <dodbm/exception.hpp>

dodbm::operations::rename_table::rename_table(const std::string& name)
    : m_name(name)
{
    if (name.empty())
    {
        throw dodbm::exception("Operation \"rename_table\" requires a valid name");
    }
}

dodbm::operation::type dodbm::operations::rename_table::get_type() const
{
    return type::rename_table;
}

const std::string& dodbm::operations::rename_table::get_name() const
{
    return m_name;
}

void dodbm::operations::rename_table::set_new_name(const std::string& name)
{
    if (name.empty())
    {
        throw dodbm::exception("Operation \"rename_table\" requires a valid new name");
    }

    m_new_name = name;
}

const std::string& dodbm::operations::rename_table::get_new_name() const
{
    if (m_new_name.empty())
    {
        throw dodbm::exception("Operation \"rename_table\" requires a valid new name to be set");
    }

    return m_new_name;
}
