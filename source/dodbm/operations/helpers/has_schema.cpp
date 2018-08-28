#include <dodbm/operations/helpers/has_schema.hpp>

void dodbm::operations::helpers::has_schema::set_schema(const std::string& name)
{
    m_schema = name;
}

const std::string& dodbm::operations::helpers::has_schema::get_schema() const
{
    return m_schema;
}
