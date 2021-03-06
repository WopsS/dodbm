#include <dodbm/db_result.hpp>
#include <dodbm/exception.hpp>

dodbm::db_result::db_result(std::vector<row> rows)
    : m_rows(std::move(rows))
{
}

const dodbm::db_result::row& dodbm::db_result::first() const
{
    return get(0);
}

bool dodbm::db_result::empty() const
{
    return m_rows.empty();
}

const dodbm::db_result::row& dodbm::db_result::get(size_t index) const
{
    return m_rows.at(index);
}

dodbm::db_result::row::row(std::unordered_map<std::string, db_value> fields)
    : m_fields(std::move(fields))
{
}

const dodbm::db_value& dodbm::db_result::row::get(const std::string& name) const
{
    return m_fields.at(name);
}
