#include <dodbm/sql_generator_helper.hpp>

const std::string dodbm::sql_generator_helper::escape_literal(const std::string& literal) const
{
    return "'" + literal + "'";
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
