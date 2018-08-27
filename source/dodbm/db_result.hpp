#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace dodbm
{
    class db_result
    {
    public:

        class row
        {
        public:

            class field
            {
            public:

                field() = default;
                ~field() = default;
            };

            row(std::unordered_map<std::string, field> fields);
            ~row() = default;

            const field& get(const std::string& name) const;

        private:

            std::unordered_map<std::string, field> m_fields;
        };

        db_result(std::vector<row> rows);
        ~db_result() = default;

        const row& get(size_t index) const;

    private:

        std::vector<row> m_rows;
    };
}