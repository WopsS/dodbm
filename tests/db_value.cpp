#include <catch2/catch.hpp>

#include <limits>

#include <dodbm/db_value.hpp>

TEST_CASE("db_value")
{
    SECTION("null")
    {
        dodbm::db_value value;
        REQUIRE(value.is_null());
    }
    SECTION("boolean")
    {
        dodbm::db_value value(true);

        REQUIRE(value.is_boolean());
        REQUIRE(value.get_boolean() == true);
    }
    SECTION("int8")
    {
        auto limit = std::numeric_limits<int8_t>::min();
        dodbm::db_value value(limit);

        REQUIRE(value.is_int8());
        REQUIRE(value.get_int8() == limit);
    }
    SECTION("uint8")
    {
        auto limit = std::numeric_limits<uint8_t>::max();
        dodbm::db_value value(limit);

        REQUIRE(value.is_uint8());
        REQUIRE(value.get_uint8() == limit);
    }
    SECTION("int16")
    {
        auto limit = std::numeric_limits<int16_t>::min();
        dodbm::db_value value(limit);

        REQUIRE(value.is_int16());
        REQUIRE(value.get_int16() == limit);
    }
    SECTION("uint16")
    {
        auto limit = std::numeric_limits<uint16_t>::max();
        dodbm::db_value value(limit);

        REQUIRE(value.is_uint16());
        REQUIRE(value.get_uint16() == limit);
    }
    SECTION("int32")
    {
        auto limit = std::numeric_limits<int32_t>::min();
        dodbm::db_value value(limit);

        REQUIRE(value.is_int32());
        REQUIRE(value.get_int32() == limit);
    }
    SECTION("uint32")
    {
        auto limit = std::numeric_limits<uint32_t>::max();
        dodbm::db_value value(limit);

        REQUIRE(value.is_uint32());
        REQUIRE(value.get_uint32() == limit);
    }
    SECTION("int64")
    {
        auto limit = std::numeric_limits<int64_t>::min();
        dodbm::db_value value(limit);

        REQUIRE(value.is_int64());
        REQUIRE(value.get_int64() == limit);
    }
    SECTION("uint64")
    {
        auto limit = std::numeric_limits<uint64_t>::max();
        dodbm::db_value value(limit);

        REQUIRE(value.is_uint64());
        REQUIRE(value.get_uint64() == limit);
    }

    SECTION("float")
    {
        auto limit = std::numeric_limits<float>::min();
        dodbm::db_value value(limit);

        REQUIRE(value.is_float());
        REQUIRE(value.get_float() == limit);
    }
    SECTION("double")
    {
        auto limit = std::numeric_limits<double>::max();
        dodbm::db_value value(limit);

        REQUIRE(value.is_double());
        REQUIRE(value.get_double() == limit);
    }
    SECTION("string")
    {
        SECTION("char*")
        {
            char hello[] = "Hello";
            dodbm::db_value value(hello);

            REQUIRE(value.is_string());
            REQUIRE(value.get_string() == hello);
        }
        SECTION("char*")
        {
            const char hello[] = "Hello";
            dodbm::db_value value(hello);

            REQUIRE(value.is_string());
            REQUIRE(value.get_string() == hello);
        }
        SECTION("std::string")
        {
            std::string hello = "Hello";
            dodbm::db_value value(hello);

            REQUIRE(value.is_string());
            REQUIRE(value.get_string() == hello);
        }
    }
}