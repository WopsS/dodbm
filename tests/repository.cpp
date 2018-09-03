#include <catch2/catch.hpp>

#include <dodbm/dodbm.hpp>
#include <mocks/collations.hpp>
#include <mocks/provider.hpp>

namespace
{
    class m20180829162057_mock_1 : public dodbm::migration
    {
    protected:

        void up(dodbm::migration_builder& builder) final
        {
            builder.ensure_schema("dodbm")
                   .collation<mocks::collations::utf8mb4_unicode_ci>();
        }

        void down(dodbm::migration_builder& builder) final
        {
            builder.drop_schema("dodbm");
        }
    };

    class m20180829162115_mock_2 : public dodbm::migration
    {
    protected:

        void up(dodbm::migration_builder& builder) final
        {
            builder.rename_table("dodbm")
                   .to("new_dodbm");
        }

        void down(dodbm::migration_builder& builder) final
        {
            builder.rename_table("new_dodbm")
                   .to("dodbm");
        }
    };

    class m20180829162152_empty : public dodbm::migration
    {
    protected:

        void up(dodbm::migration_builder& builder) final
        {
        }

        void down(dodbm::migration_builder& builder) final
        {
        }
    };
}

TEST_CASE("Repository")
{
    std::shared_ptr<mocks::provider> provider(new mocks::provider());
    dodbm::repository repository(provider);

    repository.add<m20180829162057_mock_1>();

    SECTION("Invalid migrations should throw")
    {
        repository.add<m20180829162152_empty>();

        REQUIRE_THROWS(repository.migrate());
        REQUIRE_THROWS(repository.rollback<m20180829162152_empty>());
        REQUIRE_THROWS(repository.rollback_to<m20180829162057_mock_1>());
    }
    SECTION("Valid migrations should not throw")
    {
        repository.add<m20180829162115_mock_2>();

        repository.migrate();
        repository.rollback<m20180829162115_mock_2>();
        repository.rollback_to<m20180829162057_mock_1>();
    }
}