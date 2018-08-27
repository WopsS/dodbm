#include <dodbm/operations/ensure_schema.hpp>
#include <dodbm/exception.hpp>

dodbm::operations::ensure_schema::ensure_schema(const std::string& name)
    : m_name(name)
{
    if (name.empty())
    {
        throw dodbm::exception("Operation \"ensure_schema\" requires a valid name");
    }
}

dodbm::operation::type dodbm::operations::ensure_schema::get_type() const
{
    return type::ensure_schema;
}

const std::string& dodbm::operations::ensure_schema::get_name() const
{
    return m_name;
}

void dodbm::operations::ensure_schema::set_collation(collation value)
{
    m_collation = std::move(value);
}

const dodbm::collation& dodbm::operations::ensure_schema::get_collation() const
{
    return m_collation;
}
