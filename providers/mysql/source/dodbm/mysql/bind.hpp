#pragma once

#include <string>

#include <mysql.h>

#include <dodbm/db_value.hpp>

namespace dodbm
{
    namespace mysql
    {
        class bind
        {
        public:

            bind(db_value value);
            bind(const MYSQL_FIELD& field);

            bind(const bind&) = delete;
            bind(bind&&) = delete;

            ~bind() = default;

            bind& operator=(const bind&) = delete;
            bind& operator=(bind&&) = delete;

            const db_value get_value() const;
            MYSQL_BIND* get_raw();

        private:

            void set(enum_field_types type);
            void set(enum_field_types type, size_t length);
            void set(enum_field_types type, bool is_unsigned);
            void set(enum_field_types type, size_t length, bool is_unsigned);

            MYSQL_BIND m_bind;

            db_value m_value;
            my_bool m_is_null;
            my_bool m_error;
        };
    }
}