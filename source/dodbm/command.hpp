#pragma once

#include <string>
#include <vector>

#include <dodbm/db_value.hpp>

namespace dodbm
{
    class command
    {
    public:

        command() = default;
        ~command() = default;

        command& operator<<(const std::string& rhs);

        command& operator<<(uint64_t rhs);

        void append_parameter(db_value value);
        const std::vector<db_value>& get_parameters() const;

        const std::string& get_text() const;

    private:

        std::string m_text;

        std::vector<db_value> m_paramters;
    };
}