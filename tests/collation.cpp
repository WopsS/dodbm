#include <catch2/catch.hpp>

#include <dodbm/collation.hpp>
#include <mocks/collations.hpp>

TEST_CASE("Collation")
{
    SECTION("Invalid name and charset")
    {
        using collation = mocks::collations::empty;
        REQUIRE_THROWS(dodbm::collation(collation::name, collation::charset));
    }
    SECTION("Invalid name")
    {
        using collation = mocks::collations::empty_name;
        REQUIRE_THROWS(dodbm::collation(collation::name, collation::charset));
    }
    SECTION("Invalid charset")
    {
        using collation = mocks::collations::empty_charset;
        REQUIRE_THROWS(dodbm::collation(collation::name, collation::charset));
    }
    SECTION("Empty collation")
    {
        dodbm::collation collation;

        REQUIRE(collation.empty());
        REQUIRE(std::string(collation) == "");
        REQUIRE(collation.get_charset() == "");
    }
    SECTION("Non-empty collation")
    {
        using utf8mb4_unicode_ci = mocks::collations::utf8mb4_unicode_ci;

        constexpr auto collation_name = utf8mb4_unicode_ci::name;
        constexpr auto collation_charset = utf8mb4_unicode_ci::charset;

        dodbm::collation collation(collation_name, collation_charset);

        REQUIRE(!collation.empty());
        REQUIRE(std::string(collation) == collation_name);
        REQUIRE(collation.get_charset() == collation_charset);
    }
}