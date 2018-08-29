#include <catch2/catch.hpp>

#include <dodbm/sql_generator_helper.hpp>

TEST_CASE("SQL generator helper")
{
    dodbm::sql_generator_helper helper;

    SECTION("Delimit identifier")
    {
        REQUIRE(helper.delimit_identifier("identifier") == "`identifier`");
        REQUIRE(helper.delimit_identifier("schema", "identifier") == "`schema`.`identifier`");
    }
    SECTION("Escape literal")
    {
        REQUIRE(helper.escape_literal("literal") == "'literal'");
    }
}