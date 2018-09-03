#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <dodbm/dodbm.hpp>
#include <dodbm/mysql/provider.hpp>

#include <mocks/m20180903205850_mock.hpp>
#include <mocks/m20180903211910_mock_invalid.hpp>

TEST_CASE("MySQL provider")
{
    dodbm::mysql::config config;
    config.database = "dodbm";
    config.user = "dodbm";
    config.password = "do";

    std::unique_ptr<dodbm::mysql::provider> provider(new dodbm::mysql::provider(config));
    dodbm::repository repository(std::move(provider));

    repository.add<mocks::m20180903205850_mock>();

    SECTION("Valid migration should not throw")
    {
        repository.migrate();
        repository.rollback<mocks::m20180903205850_mock>();
    }
    SECTION("Invalid migration should throw")
    {
        repository.add<mocks::m20180903211910_mock_invalid>();

        REQUIRE_THROWS(repository.migrate());
        REQUIRE_THROWS(repository.rollback<mocks::m20180903211910_mock_invalid>());
    }
}