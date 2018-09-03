#include <dodbm/mysql/bind.hpp>
#include <dodbm/mysql/exception.hpp>

dodbm::mysql::bind::bind(db_value value)
    : m_bind({})
    , m_value(std::move(value))
    , m_is_null(false)
    , m_error(false)
{
    m_bind.buffer = m_value.get_union_ptr();
    m_bind.length = &m_bind.buffer_length;
    m_bind.is_null = &m_is_null;
    m_bind.error = &m_error;

    using type = dodbm::db_value::type;
    switch (m_value.get_type())
    {
        case type::null:
        {
            set(MYSQL_TYPE_NULL);
            break;
        }
        case type::boolean:
        {
            set(MYSQL_TYPE_TINY);
            break;
        }
        case type::int8:
        {
            set(MYSQL_TYPE_TINY, false);
            break;
        }
        case type::uint8:
        {
            set(MYSQL_TYPE_TINY, true);
            break;
        }
        case type::int16:
        {
            set(MYSQL_TYPE_SHORT, false);
            break;
        }
        case type::uint16:
        {
            set(MYSQL_TYPE_SHORT, true);
            break;
        }
        case type::int32:
        {
            set(MYSQL_TYPE_LONG, false);
            break;
        }
        case type::uint32:
        {
            set(MYSQL_TYPE_LONG, true);
            break;
        }
        case type::int64:
        {
            set(MYSQL_TYPE_LONGLONG, false);
            break;
        }
        case type::uint64:
        {
            set(MYSQL_TYPE_LONGLONG, true);
            break;
        }
        case type::float_number:
        {
            set(MYSQL_TYPE_FLOAT);
            break;
        }
        case type::double_number:
        {
            set(MYSQL_TYPE_DOUBLE);
            break;
        }
        case type::string:
        {
            set(MYSQL_TYPE_STRING, m_value.size());
            break;
        }
        default:
        {
            throw dodbm::mysql::exception("Unknown value type in bind (" + std::to_string(static_cast<uint32_t>(m_value.get_type())) + ")");
        }
    }
}

dodbm::mysql::bind::bind(const MYSQL_FIELD& field)
    : bind(db_value())
{
    set(field.type, field.max_length, field.flags & UNSIGNED_FLAG);
}

const dodbm::db_value dodbm::mysql::bind::get_value() const
{
    return m_value;
}

MYSQL_BIND* dodbm::mysql::bind::get_raw()
{
    return &m_bind;
}

void dodbm::mysql::bind::set(enum_field_types type)
{
    set(type, 0, false);
}

void dodbm::mysql::bind::set(enum_field_types type, size_t length)
{
    set(type, length, false);
}

void dodbm::mysql::bind::set(enum_field_types type, bool is_unsigned)
{
    set(type, 0, is_unsigned);
}

void dodbm::mysql::bind::set(enum_field_types type, size_t length, bool is_unsigned)
{
    m_bind.buffer_type = type;
    m_bind.is_unsigned = is_unsigned;

    switch (type)
    {
        case MYSQL_TYPE_NULL:
        {
            m_bind.buffer_length = 1;
            break;
        }
        case MYSQL_TYPE_TINY:
        case MYSQL_TYPE_BIT:
        {
            if (is_unsigned)
            {
                m_value = uint8_t();
            }
            else
            {
                m_value = int8_t();
            }

            m_bind.buffer_length = 1;
            break;
        }
        case MYSQL_TYPE_SHORT:
        case MYSQL_TYPE_YEAR:
        {
            if (is_unsigned)
            {
                m_value = uint16_t();
            }
            else
            {
                m_value = int16_t();
            }

            m_bind.buffer_length = sizeof(int16_t);
            break;
        }
        case MYSQL_TYPE_LONG:
        case MYSQL_TYPE_INT24:
        {
            if (is_unsigned)
            {
                m_value = uint32_t();
            }
            else
            {
                m_value = int32_t();
            }

            m_bind.buffer_length = sizeof(int32_t);
            break;
        }
        case MYSQL_TYPE_LONGLONG:
        {
            if (is_unsigned)
            {
                m_value = uint64_t();
            }
            else
            {
                m_value = int64_t();
            }

            m_bind.buffer_length = sizeof(int64_t);
            break;
        }
        case MYSQL_TYPE_FLOAT:
        {
            m_value = float();
            m_bind.buffer_length = sizeof(float);

            break;
         }
        case MYSQL_TYPE_DOUBLE:
        {
            m_value = double();
            m_bind.buffer_length = sizeof(double);

            break;
        }
        case MYSQL_TYPE_BLOB:
        case MYSQL_TYPE_DECIMAL:
        case MYSQL_TYPE_ENUM:
        case MYSQL_TYPE_LONG_BLOB:
        case MYSQL_TYPE_MEDIUM_BLOB:
        case MYSQL_TYPE_NEWDECIMAL:
        case MYSQL_TYPE_STRING:
        case MYSQL_TYPE_TINY_BLOB:
        case MYSQL_TYPE_VARCHAR:
        case MYSQL_TYPE_VAR_STRING:
        {
            if (length)
            {
                if (!m_value.is_string())
                {
                    m_value = "";
                }

                m_value.resize(length);

                m_bind.buffer = const_cast<char*>(m_value.data());
                m_bind.buffer_length = m_value.size();
            }
            else
            {
                m_bind.buffer = nullptr;
                m_bind.buffer_length = 0;
            }
            break;
        }
        default:
        {
            throw dodbm::mysql::exception("Unsupported bind type (" + std::to_string(type) + ")");
        }
    }
}
