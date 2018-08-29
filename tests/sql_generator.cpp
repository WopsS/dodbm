#include <catch2/catch.hpp>

#include <dodbm/operations/alter_database.hpp>
#include <dodbm/operations/alter_table.hpp>
#include <dodbm/operations/create_table.hpp>
#include <dodbm/operations/drop_schema.hpp>
#include <dodbm/operations/drop_table.hpp>
#include <dodbm/operations/ensure_schema.hpp>
#include <dodbm/operations/rename_table.hpp>

#include <mocks/collations.hpp>
#include <mocks/storage_engines.hpp>
#include <mocks/provider.hpp>

TEST_CASE("SQL generator")
{
    using utf8mb4_unicode_ci = mocks::collations::utf8mb4_unicode_ci;
    using InnoDB = mocks::storage_engines::InnoDB;

    mocks::provider provider;

    auto generator = provider.get_sql_generator();
    auto helper = provider.get_sql_generator_helper();

    SECTION("alter_database")
    {
        dodbm::operations::alter_database operation("dodbm");

        SECTION("without collation")
        {
            REQUIRE_THROWS(generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper));
        }
        SECTION("with collation")
        {
            operation.set_collation(dodbm::collation(utf8mb4_unicode_ci::name, utf8mb4_unicode_ci::charset));

            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "ALTER DATABASE `dodbm` DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci");
        }
    }
    SECTION("ensure_schema")
    {
        dodbm::operations::ensure_schema operation("dodbm");

        SECTION("without collation")
        {
            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "CREATE SCHEMA IF NOT EXISTS `dodbm`");
        }
        SECTION("with collation")
        {
            operation.set_collation(dodbm::collation(utf8mb4_unicode_ci::name, utf8mb4_unicode_ci::charset));

            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "CREATE SCHEMA IF NOT EXISTS `dodbm` DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci");
        }
    }
    SECTION("drop_schema")
    {
        dodbm::operations::drop_schema operation("dodbm");

        auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
        REQUIRE(command.get_text() == "DROP SCHEMA `dodbm`");
    }
    SECTION("ensure_schema")
    {
        dodbm::operations::ensure_schema operation("dodbm");

        SECTION("without collation")
        {
            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "CREATE SCHEMA IF NOT EXISTS `dodbm`");
        }
        SECTION("with collation")
        {
            operation.set_collation(dodbm::collation(utf8mb4_unicode_ci::name, utf8mb4_unicode_ci::charset));

            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "CREATE SCHEMA IF NOT EXISTS `dodbm` DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci");
        }
    }
    SECTION("drop_schema")
    {
        dodbm::operations::drop_schema operation("dodbm");

        auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
        REQUIRE(command.get_text() == "DROP SCHEMA `dodbm`");
    }
    SECTION("create_table")
    {
        dodbm::operations::create_table operation("dbm");
        operation.set_schema("do");

        SECTION("without options")
        {
            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "CREATE TABLE `do`.`dbm` ()");
        }
        SECTION("with options")
        {
            operation.set_collation(dodbm::collation(utf8mb4_unicode_ci::name, utf8mb4_unicode_ci::charset));
            operation.set_comment("Hello");
            operation.set_engine(dodbm::storage_engine(InnoDB::name));

            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "CREATE TABLE `do`.`dbm` () ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Hello'");
        }
    }
    SECTION("drop_table")
    {
        dodbm::operations::drop_table operation("dbm");
        operation.set_schema("do");

        auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
        REQUIRE(command.get_text() == "DROP TABLE `do`.`dbm`");
    }
    SECTION("alter_table")
    {
        dodbm::operations::alter_table operation("dbm");
        operation.set_schema("do");

        SECTION("without options")
        {
            REQUIRE_THROWS(generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper));
        }
        SECTION("with options")
        {
            operation.set_collation(dodbm::collation(utf8mb4_unicode_ci::name, utf8mb4_unicode_ci::charset));
            operation.set_comment("Hello");
            operation.set_engine(dodbm::storage_engine(InnoDB::name));

            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='Hello'");
        }
    }
    SECTION("rename_table")
    {
        dodbm::operations::rename_table operation("dbm");
        operation.set_schema("do");
        operation.set_new_name("dodbm");

        auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
        REQUIRE(command.get_text() == "RENAME TABLE `do`.`dbm` TO `do`.`dodbm`");
    }
}