#include <dodbm/sql_generator_helper.hpp>

const std::string dodbm::sql_generator_helper::escape_literal(const std::string& literal) const
{
    return "'" + literal + "'";
}

const std::string dodbm::sql_generator_helper::delimit_identifier(const std::string& identifier) const
{
    return "`" + identifier + "`";
}

const std::string dodbm::sql_generator_helper::delimit_identifier(const std::string& table, const std::string& column) const
{
    return delimit_identifier(table) + "." + delimit_identifier(column);
}
