#include <dodbm/operations/drop_schema.hpp>
#include <dodbm/exception.hpp>

dodbm::operations::drop_schema::drop_schema(const std::string& name)
    : m_name(name)
{
    if (name.empty())
    {
        throw dodbm::exception("Operation \"drop_schema\" requires a valid name");
    }
}

dodbm::operation::type dodbm::operations::drop_schema::get_type() const
{
    return type::drop_schema;
}

const std::string& dodbm::operations::drop_schema::get_name() const
{
    return m_name;
}
