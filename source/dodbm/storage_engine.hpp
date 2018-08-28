#pragma once

#include <string>

namespace dodbm
{
    class storage_engine
    {
    public:

        storage_engine() = default;
        storage_engine(const std::string& name);

        ~storage_engine() = default;

        operator const std::string() const;

        bool empty() const;

    private:

        std::string m_name;
    };
}