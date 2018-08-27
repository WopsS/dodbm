#pragma once

#include <string>

namespace dodbm
{
    class sql_generator_helper
    {
    public:

        sql_generator_helper() = default;
        virtual ~sql_generator_helper() = default;

        virtual const std::string escape_literal(const std::string& literal) const;

        virtual const std::string delimit_identifier(const std::string& identifier) const;

        virtual const std::string delimit_identifier(const std::string& table, const std::string& column) const;
    };
}