#include <dodbm/operation_with_schema.hpp>

void dodbm::operation_with_schema::set_schema(const std::string& name)
{
    m_schema = name;
}

const std::string& dodbm::operation_with_schema::get_schema() const
{
    return m_schema;
}
