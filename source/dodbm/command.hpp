#pragma once

#include <string>

namespace dodbm
{
    class command
    {
    public:

        command() = default;
        ~command() = default;

        command& operator<<(const std::string& rhs);

    private:

        std::string m_text;
    };
}