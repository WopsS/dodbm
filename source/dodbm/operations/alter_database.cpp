#include <dodbm/operations/alter_database.hpp>
#include <dodbm/exception.hpp>

dodbm::operations::alter_database::alter_database(const std::string& name)
    : m_name(name)
{
    if (name.empty())
    {
        throw dodbm::exception("Operation \"alter_database\" requires a valid name");
    }
}

dodbm::operation::type dodbm::operations::alter_database::get_type() const
{
    return type::alter_database;
}

const std::string& dodbm::operations::alter_database::get_name() const
{
    return m_name;
}

void dodbm::operations::alter_database::set_collation(collation value)
{
    m_collation = std::move(value);
}

const dodbm::collation& dodbm::operations::alter_database::get_collation() const
{
    return m_collation;
}
