#pragma once

namespace dodbm
{
    namespace mysql
    {
        inline namespace numeric
        {
            struct boolean
            {
                static constexpr auto name = "BOOLEAN";
            };

            struct bit
            {
                static constexpr auto name = "BIT";
            };

            struct tinyint
            {
                static constexpr auto name = "TINYINT";
            };

            struct smallint
            {
                static constexpr auto name = "SMALLINT";
            };

            struct mediumint
            {
                static constexpr auto name = "MEDIUMINT";
            };

            // Equivalent for "INT" type.
            struct int_t
            {
                static constexpr auto name = "INT";
            };

            struct bigint
            {
                static constexpr auto name = "BIGINT";
            };

            struct decimal
            {
                static constexpr auto name = "DECIMAL";
            };

            // Equivalent for "FLOAT" type.
            struct float_t
            {
                static constexpr auto name = "FLOAT";
            };

            // Equivalent for "DOUBLE" type.
            struct double_t
            {
                static constexpr auto name = "DOUBLE";
            };

            struct real
            {
                static constexpr auto name = "REAL";
            };

            struct serial
            {
                static constexpr auto name = "SERIAL";
            };
        }

        inline namespace date_and_time
        {
            struct time
            {
                static constexpr auto name = "TIME";
            };

            struct date
            {
                static constexpr auto name = "DATE";
            };

            struct datetime
            {
                static constexpr auto name = "DATETIME";
            };

            struct timestamp
            {
                static constexpr auto name = "TIMESTAMP";
            };

            struct year
            {
                static constexpr auto name = "YEAR";
            };
        }

        inline namespace string
        {
            // Equivalent for "CHAR" type.
            struct char_t
            {
                static constexpr auto name = "CHAR";
            };

            struct varchar
            {
                static constexpr auto name = "VARCHAR";
            };

            struct tinytext
            {
                static constexpr auto name = "TINYTEXT";
            };

            struct text
            {
                static constexpr auto name = "TEXT";
            };

            struct longtext
            {
                static constexpr auto name = "LONGTEXT";
            };

            struct binary
            {
                static constexpr auto name = "BINARY";
            };

            struct varbinary
            {
                static constexpr auto name = "VARBINARY";
            };

            struct tinyblob
            {
                static constexpr auto name = "TINYBLOB";
            };

            struct mediumblob
            {
                static constexpr auto name = "MEDIUMBLOB";
            };

            struct blob
            {
                static constexpr auto name = "BLOB";
            };

            struct longblob
            {
                static constexpr auto name = "LONGBLOB";
            };

            // Equivalent for "ENUM" type.
            struct enum_t
            {
                static constexpr auto name = "ENUM";
            };

            struct set
            {
                static constexpr auto name = "SET";
            };
        }

        inline namespace spatial
        {
            struct geometry
            {
                static constexpr auto name = "GEOMETRY";
            };

            struct point
            {
                static constexpr auto name = "POINT";
            };

            struct linestring
            {
                static constexpr auto name = "LINESTRING";
            };

            struct polygon
            {
                static constexpr auto name = "POLYGON";
            };

            struct multipoint
            {
                static constexpr auto name = "MULTIPOINT";
            };

            struct multilinestring
            {
                static constexpr auto name = "MULTILINESTRING";
            };

            struct multipolygon
            {
                static constexpr auto name = "MULTIPOLYGON";
            };

            struct geometrycollection
            {
                static constexpr auto name = "GEOMETRYCOLLECTION";
            };
        }

        inline namespace json
        {
            struct json
            {
                static constexpr auto name = "JSON";
            };
        }
    }
}