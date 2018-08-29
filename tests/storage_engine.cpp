#include <catch2/catch.hpp>

#include <dodbm/storage_engine.hpp>
#include <mocks/storage_engines.hpp>

TEST_CASE("Storage engine")
{
    SECTION("Invalid name")
    {
        REQUIRE_THROWS(dodbm::storage_engine(mocks::storage_engines::empty::name));
    }
    SECTION("Empty storage engine")
    {
        dodbm::storage_engine engine;

        REQUIRE(engine.empty());
        REQUIRE(std::string(engine) == "");
    }
    SECTION("Non-empty storage engine")
    {
        using InnoDB = mocks::storage_engines::InnoDB;
        constexpr auto engine_name = InnoDB::name;

        dodbm::storage_engine engine(engine_name);

        REQUIRE(!engine.empty());
        REQUIRE(std::string(engine) == engine_name);
    }
}