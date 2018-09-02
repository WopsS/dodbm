#include <dodbm/operations/custom_sql.hpp>
#include <dodbm/exception.hpp>

dodbm::operations::custom_sql::custom_sql(const std::string& sql)
    : m_sql(sql)
{
    if (sql.empty())
    {
        throw dodbm::exception("Operation \"custom_sql\" require a vaild SQL command");
    }
}

dodbm::operation::type dodbm::operations::custom_sql::get_type() const
{
    return type::custom_sql;
}

const std::string& dodbm::operations::custom_sql::get_sql() const
{
    return m_sql;
}
