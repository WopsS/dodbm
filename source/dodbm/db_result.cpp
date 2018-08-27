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

dodbm::db_result::row::row(std::unordered_map<std::string, field> fields)
    : m_fields(std::move(fields))
{
}

const dodbm::db_result::row::field& dodbm::db_result::row::get(const std::string& name) const
{
    return m_fields.at(name);
}

const bool dodbm::db_result::row::field::as_bool() const
{
    throw dodbm::exception("as_bool() is not implemented");
}

const int8_t dodbm::db_result::row::field::as_int8() const
{
    throw dodbm::exception("as_int8() is not implemented");
}

const uint8_t dodbm::db_result::row::field::as_uint8() const
{
    throw dodbm::exception("as_uint8() is not implemented");
}

const int16_t dodbm::db_result::row::field::as_int16() const
{
    throw dodbm::exception("as_int16() is not implemented");
}

const uint16_t dodbm::db_result::row::field::as_uint16() const
{
    throw dodbm::exception("as_uint16() is not implemented");
}

const int32_t dodbm::db_result::row::field::as_int32() const
{
    throw dodbm::exception("as_int32() is not implemented");
}

const uint32_t dodbm::db_result::row::field::as_uint32() const
{
    throw dodbm::exception("as_uint32() is not implemented");
}

const int64_t dodbm::db_result::row::field::as_int64() const
{
    throw dodbm::exception("as_int64() is not implemented");
}

const uint64_t dodbm::db_result::row::field::as_uint64() const
{
    throw dodbm::exception("as_uint64() is not implemented");
}

const std::string dodbm::db_result::row::field::as_string() const
{
    throw dodbm::exception("as_string() is not implemented");
}
