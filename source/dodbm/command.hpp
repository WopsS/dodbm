#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <dodbm/db_value.hpp>

namespace dodbm
{
    class command
    {
    public:

        command(bool allowed_in_prepared_statements = true);
        ~command() = default;

        command& operator<<(char* rhs);
        command& operator<<(const char* rhs);
        command& operator<<(const std::string& rhs);

        template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
        command& operator<<(T rhs)
        {
            m_text += std::to_string(rhs);
            return *this;
        }

        void append_parameter(db_value value);
        const std::vector<db_value>& get_parameters() const;

        const std::string& get_text() const;

        bool is_allowed_in_prepared_statements() const;

    private:

        bool m_allowed_in_prepared_statements;

        std::string m_text;

        std::vector<db_value> m_paramters;
    };
}