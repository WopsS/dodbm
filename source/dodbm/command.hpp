#pragma once

#include <string>

#include <dodbm/db_result.hpp>

namespace dodbm
{
    class command
    {
    public:

        command() = default;
        ~command() = default;

        command& operator<<(const std::string& rhs);

        virtual void execute_non_query() = 0;

        virtual db_result execute_query() = 0;

    private:

        std::string m_text;
    };
}