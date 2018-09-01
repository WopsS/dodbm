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

        command& operator<<(uint64_t rhs);

        const std::string get_text() const;

    private:

        std::string m_text;
    };
}