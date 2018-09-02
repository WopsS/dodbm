#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

#include <dodbm/db_value.hpp>

namespace dodbm
{
    class db_result
    {
    public:

        class row
        {
        public:

            row(std::unordered_map<std::string, db_value> fields);
            ~row() = default;

            const db_value& get(const std::string& name) const;

        private:

            std::unordered_map<std::string, db_value> m_fields;
        };

        db_result(std::vector<row> rows);
        ~db_result() = default;

        const row& first() const;

        bool empty() const; 

        const row& get(size_t index) const;

    private:

        std::vector<row> m_rows;
    };
}