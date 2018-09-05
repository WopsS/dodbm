#pragma once

#include <string>

namespace dodbm
{
    class collation
    {
    public:

        collation() = default;
        collation(const std::string& name, const std::string& charset);

        ~collation() = default;

        operator const std::string() const; 

        bool empty() const;

        const std::string& get_charset() const;

    private:
        
        static std::string m_default_name;
        static std::string m_default_charset;

        std::string m_name;
        std::string m_charset;
    };
}