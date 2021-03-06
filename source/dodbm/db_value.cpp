#include <dodbm/db_value.hpp>
#include <dodbm/exception.hpp>

dodbm::db_value::db_value()
    : m_type(type::null)
{
}

dodbm::db_value::db_value(bool value)
    : m_type(type::boolean)
    , b(value)
{
}

dodbm::db_value::db_value(int8_t value)
    : m_type(type::int8)
    , int8(value)
{
}

dodbm::db_value::db_value(uint8_t value)
    : m_type(type::uint8)
    , uint8(value)
{
}

dodbm::db_value::db_value(int16_t value)
    : m_type(type::int16)
    , int16(value)
{
}

dodbm::db_value::db_value(uint16_t value)
    : m_type(type::uint16)
    , uint16(value)
{
}

dodbm::db_value::db_value(int32_t value)
    : m_type(type::int32)
    , int32(value)
{
}

dodbm::db_value::db_value(uint32_t value)
    : m_type(type::uint32)
    , uint32(value)
{
}

dodbm::db_value::db_value(int64_t value)
    : m_type(type::int64)
    , int64(value)
{
}

dodbm::db_value::db_value(uint64_t value)
    : m_type(type::uint64)
    , uint64(value)
{
}

dodbm::db_value::db_value(float value)
    : m_type(type::float_number)
    , f(value)
{
}

dodbm::db_value::db_value(double value)
    : m_type(type::double_number)
    , d(value)
{
}

dodbm::db_value::db_value(char* value)
    : m_type(type::string)
    , string(value)
{
}

dodbm::db_value::db_value(const char* value)
    : m_type(type::string)
    , string(value)
{
}

dodbm::db_value::db_value(const std::string& value)
    : m_type(type::string)
    , string(value)
{
}

dodbm::db_value::db_value(const db_value& other)
{
    handle_copy(other);
}

dodbm::db_value::db_value(db_value&& other)
{
    handle_move(std::move(other));
}

dodbm::db_value::~db_value()
{
    switch (m_type)
    {
        case type::string:
        {
            string.~basic_string();
            break;
        }
    }
}

dodbm::db_value& dodbm::db_value::operator=(const db_value& other)
{
    handle_copy(other);
    return *this;
}

dodbm::db_value& dodbm::db_value::operator=(db_value&& other)
{
    handle_move(std::move(other));
    return *this;
}

void dodbm::db_value::operator=(bool rhs)
{
    b = rhs;
    m_type = type::boolean;
}

void dodbm::db_value::operator=(int8_t rhs)
{
    int8 = rhs;
    m_type = type::int8;
}

void dodbm::db_value::operator=(uint8_t rhs)
{
    uint8 = rhs;
    m_type = type::uint8;
}

void dodbm::db_value::operator=(int16_t rhs)
{
    int16 = rhs;
    m_type = type::int16;
}

void dodbm::db_value::operator=(uint16_t rhs)
{
    uint16 = rhs;
    m_type = type::uint16;
}

void dodbm::db_value::operator=(int32_t rhs)
{
    int32 = rhs;
    m_type = type::int32;
}

void dodbm::db_value::operator=(uint32_t rhs)
{
    uint32 = rhs;
    m_type = type::uint32;
}

void dodbm::db_value::operator=(int64_t rhs)
{
    int64 = rhs;
    m_type = type::int64;
}

void dodbm::db_value::operator=(uint64_t rhs)
{
    uint64 = rhs;
    m_type = type::uint64;
}

void dodbm::db_value::operator=(float rhs)
{
    f = rhs;
    m_type = type::float_number;
}

void dodbm::db_value::operator=(double rhs)
{
    d = rhs;
    m_type = type::double_number;
}

void dodbm::db_value::operator=(char* rhs)
{
    string = std::string(rhs);
    m_type = type::string;
}

void dodbm::db_value::operator=(const char* rhs)
{
    string = std::string(rhs);
    m_type = type::string;
}

void dodbm::db_value::operator=(const std::string& rhs)
{
    string = std::string(rhs);
    m_type = type::string;
}

dodbm::db_value::type dodbm::db_value::get_type() const
{
    return m_type;
}

bool dodbm::db_value::is_null() const
{
    return m_type == type::null;
}

bool dodbm::db_value::get_boolean() const
{
    return b;
}

bool dodbm::db_value::is_boolean() const
{
    return m_type == type::boolean;
}

int8_t dodbm::db_value::get_int8() const
{
    return int8;
}

uint8_t dodbm::db_value::get_uint8() const
{
    return uint8;
}

bool dodbm::db_value::is_int8() const
{
    return m_type == type::int8;
}

bool dodbm::db_value::is_uint8() const
{
    return m_type == type::uint8;
}

int16_t dodbm::db_value::get_int16() const
{
    return int16;
}

uint16_t dodbm::db_value::get_uint16() const
{
    return uint16;
}

bool dodbm::db_value::is_int16() const
{
    return m_type == type::int16;
}

bool dodbm::db_value::is_uint16() const
{
    return m_type == type::uint16;
}

int32_t dodbm::db_value::get_int32() const
{
    return int32;
}

uint32_t dodbm::db_value::get_uint32() const
{
    return uint32;
}

bool dodbm::db_value::is_int32() const
{
    return m_type == type::int32;
}

bool dodbm::db_value::is_uint32() const
{
    return m_type == type::uint32;
}

int64_t dodbm::db_value::get_int64() const
{
    return int64;
}

uint64_t dodbm::db_value::get_uint64() const
{
    return uint64;
}

bool dodbm::db_value::is_int64() const
{
    return m_type == type::int64;
}

bool dodbm::db_value::is_uint64() const
{
    return m_type == type::uint64;
}

float dodbm::db_value::get_float() const
{
    return f;
}

bool dodbm::db_value::is_float() const
{
    return m_type == type::float_number;
}

double dodbm::db_value::get_double() const
{
    return d;
}

bool dodbm::db_value::is_double() const
{
    return m_type == type::double_number;
}

const std::string dodbm::db_value::get_string() const
{
    return string;
}

bool dodbm::db_value::is_string() const
{
    return m_type == type::string;
}

const char* dodbm::db_value::data() const
{
    if (is_string())
    {
        return string.data();
    }

    return nullptr;
}

std::size_t dodbm::db_value::size() const
{
    if (is_string())
    {
        return string.size();
    }

    return 0;
}

void dodbm::db_value::resize(std::size_t new_size)
{
    if (is_string())
    {
        string.resize(new_size);
    }
}

void* dodbm::db_value::get_union_ptr()
{
    return reinterpret_cast<void*>(&b);
}

void dodbm::db_value::handle_copy(const db_value& other)
{
    if (this != &other)
    {
        m_type = other.m_type;
        switch (m_type)
        {
            case type::null:
            {
                break;
            }
            case type::boolean:
            {
                b = other.b;
                break;
            }
            case type::int8:
            {
                int8 = other.int8;
                break;
            }
            case type::uint8:
            {
                uint8 = other.uint8;
                break;
            }
            case type::int16:
            {
                int16 = other.int16;
                break;
            }
            case type::uint16:
            {
                uint16 = other.uint16;
                break;
            }
            case type::int32:
            {
                int32 = other.int32;
                break;
            }
            case type::uint32:
            {
                uint32 = other.uint32;
                break;
            }
            case type::int64:
            {
                int64 = other.int64;
                break;
            }
            case type::uint64:
            {
                uint64 = other.uint64;
                break;
            }
            case type::float_number:
            {
                f = other.f;
                break;
            }
            case type::double_number:
            {
                d = other.d;
                break;
            }
            case type::string:
            {
                new (&string) auto(other.string);
                break;
            }
            default:
            {
                throw dodbm::exception("Unhandled DB value type (" + std::to_string(static_cast<uint32_t>(m_type)) + ")");
            }
        }
    }
}

void dodbm::db_value::handle_move(db_value&& other)
{
    m_type = other.m_type;
    switch (m_type)
    {
        case type::null:
        {
            break;
        }
        case type::boolean:
        {
            b = other.b;
            break;
        }
        case type::int8:
        {
            int8 = other.int8;
            break;
        }
        case type::uint8:
        {
            uint8 = other.uint8;
            break;
        }
        case type::int16:
        {
            int16 = other.int16;
            break;
        }
        case type::uint16:
        {
            uint16 = other.uint16;
            break;
        }
        case type::int32:
        {
            int32 = other.int32;
            break;
        }
        case type::uint32:
        {
            uint32 = other.uint32;
            break;
        }
        case type::int64:
        {
            int64 = other.int64;
            break;
        }
        case type::uint64:
        {
            uint64 = other.uint64;
            break;
        }
        case type::float_number:
        {
            f = other.f;
            break;
        }
        case type::double_number:
        {
            d = other.d;
            break;
        }
        case type::string:
        {
            new (&string) auto(std::move(other.string));
            break;
        }
        default:
        {
            throw dodbm::exception("Unhandled DB value type (" + std::to_string(static_cast<uint32_t>(m_type)) + ")");
        }
    }
}
