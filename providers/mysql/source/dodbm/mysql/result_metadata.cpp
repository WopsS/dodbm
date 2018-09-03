#include <dodbm/mysql/result_metadata.hpp>

dodbm::mysql::result_metadata::result_metadata(MYSQL_STMT* stmt)
    : m_result(mysql_stmt_result_metadata(stmt))
{
}

dodbm::mysql::result_metadata::~result_metadata()
{
    if (m_result)
    {
        mysql_free_result(m_result);
        m_result = nullptr;
    }
}

MYSQL_RES* dodbm::mysql::result_metadata::get() const
{
    return m_result;
}
