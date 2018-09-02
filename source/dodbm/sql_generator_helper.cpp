#include <dodbm/sql_generator_helper.hpp>

const std::string dodbm::sql_generator_helper::escape_literal(const std::string& literal) const
{
    std::regex re("'");
    auto result = std::regex_replace(literal, re, "\\$&");
    return "'" + result + "'";
}

const std::string dodbm::sql_generator_helper::escape_value(const db_value& value) const
{
    using type = dodbm::db_value::type;

    switch (value.get_type())
    {
        case type::boolean:
        {
            return std::to_string(value.get_boolean());
        }
        case type::int8:
        {
            return std::to_string(value.get_int8());
        }
        case type::uint8:
        {
            return std::to_string(value.get_uint8());
        }
        case type::int16:
        {
            return std::to_string(value.get_int16());
        }
        case type::uint16:
        {
            return std::to_string(value.get_uint16());
        }
        case type::int32:
        {
            return std::to_string(value.get_int32());
        }
        case type::uint32:
        {
            return std::to_string(value.get_uint32());
        }
        case type::int64:
        {
            return std::to_string(value.get_int64());
        }
        case type::uint64:
        {
            return std::to_string(value.get_uint64());
        }
        case type::float_number:
        {
            return std::to_string(value.get_float());
        }
        case type::double_number:
        {
            return std::to_string(value.get_double());
        }
        case type::string:
        {
            return "?";
        }
    }

    return "NULL";
}

const std::string dodbm::sql_generator_helper::delimit_identifier(const std::string& identifier) const
{
    return "`" + identifier + "`";
}

const std::string dodbm::sql_generator_helper::delimit_identifier(const std::string& schema, const std::string& table) const
{
    std::string prefix;
    if (!schema.empty())
    {
        prefix = delimit_identifier(schema) + ".";
    }


    return prefix + delimit_identifier(table);
}
