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

                const bool as_bool() const;

                const int8_t as_int8() const;
                const uint8_t as_uint8() const;

                const int16_t as_int16() const;
                const uint16_t as_uint16() const;

                const int32_t as_int32() const;
                const uint32_t as_uint32() const;

                const int64_t as_int64() const;
                const uint64_t as_uint64() const;

                const std::string as_string() const;
            };

            row(std::unordered_map<std::string, field> fields);
            ~row() = default;

            const field& get(const std::string& name) const;

        private:

            std::unordered_map<std::string, field> m_fields;
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