#pragma once

#include <cstdint>
#include <string>

namespace dodbm
{
    class db_value
    {
    public:

        enum class type : uint8_t
        {
            null,
            boolean,

            int8,
            uint8,

            int16,
            uint16,

            int32,
            uint32,

            int64,
            uint64,

            float_number,
            double_number,

            string
        };

        db_value();

        db_value(bool value);

        db_value(int8_t value);
        db_value(uint8_t value);

        db_value(int16_t value);
        db_value(uint16_t value);

        db_value(int32_t value);
        db_value(uint32_t value);

        db_value(int64_t value);
        db_value(uint64_t value);

        db_value(float value);

        db_value(double value);

        db_value(char* value);
        db_value(const char* value);
        db_value(const std::string& value);

        db_value(const db_value& other);
        db_value(db_value&& other);

        ~db_value();

        db_value& operator=(const db_value& other);
        db_value& operator=(db_value&& other);

        void operator=(bool rhs);

        void operator=(int8_t rhs);
        void operator=(uint8_t rhs);

        void operator=(int16_t rhs);
        void operator=(uint16_t rhs);

        void operator=(int32_t rhs);
        void operator=(uint32_t rhs);

        void operator=(int64_t rhs);
        void operator=(uint64_t rhs);

        void operator=(float rhs);
        void operator=(double rhs);

        void operator=(char* rhs);
        void operator=(const char* rhs);
        void operator=(const std::string& rhs);

        type get_type() const;

        bool is_null() const;

        bool get_boolean() const;
        bool is_boolean() const;

        int8_t get_int8() const;
        uint8_t get_uint8() const;

        bool is_int8() const;
        bool is_uint8() const;

        int16_t get_int16() const;
        uint16_t get_uint16() const;

        bool is_int16() const;
        bool is_uint16() const;

        int32_t get_int32() const;
        uint32_t get_uint32() const;

        bool is_int32() const;
        bool is_uint32() const;

        int64_t get_int64() const;
        uint64_t get_uint64() const;

        bool is_int64() const;
        bool is_uint64() const;

        float get_float() const;
        bool is_float() const;

        double get_double() const;
        bool is_double() const;

        const std::string get_string() const;
        bool is_string() const;

        const char* data() const;
        std::size_t size() const;
        void resize(std::size_t new_size);

        void* get_union_ptr();

    private:

        void handle_copy(const db_value& other);
        void handle_move(db_value&& other);

        union
        {
            char _initialization[sizeof(std::string)]{};

            bool b;

            int8_t int8;
            uint8_t uint8;

            int16_t int16;
            uint16_t uint16;

            int32_t int32;
            uint32_t uint32;

            int64_t int64;
            uint64_t uint64;

            float f;
            double d;

            std::string string;
        };

        type m_type;
    };
}