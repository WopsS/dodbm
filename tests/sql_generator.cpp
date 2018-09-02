#include <catch2/catch.hpp>

#include <dodbm/operations/alter_database.hpp>

#include <dodbm/operations/drop_schema.hpp>
#include <dodbm/operations/ensure_schema.hpp>

#include <dodbm/operations/alter_table.hpp>
#include <dodbm/operations/create_table.hpp>
#include <dodbm/operations/drop_table.hpp>
#include <dodbm/operations/rename_table.hpp>

#include <dodbm/operations/add_column.hpp>
#include <dodbm/operations/alter_column.hpp>
#include <dodbm/operations/drop_column.hpp>
#include <dodbm/operations/rename_column.hpp>

#include <dodbm/operations/add_primary_key.hpp>
#include <dodbm/operations/drop_primary_key.hpp>

#include <dodbm/operations/add_foreign_key.hpp>
#include <dodbm/operations/drop_foreign_key.hpp>

#include <dodbm/operations/add_unique_constraint.hpp>
#include <dodbm/operations/drop_unique_constraint.hpp>

#include <dodbm/operations/create_index.hpp>
#include <dodbm/operations/drop_index.hpp>
#include <dodbm/operations/rename_index.hpp>

#include <mocks/collations.hpp>
#include <mocks/provider.hpp>
#include <mocks/storage_engines.hpp>
#include <mocks/types.hpp>

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
            REQUIRE(command.get_text() == "ALTER DATABASE `dodbm` CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci");
        }
    }
    // Schema.
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
            REQUIRE(command.get_text() == "CREATE SCHEMA IF NOT EXISTS `dodbm` CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci");
        }
    }
    SECTION("drop_schema")
    {
        dodbm::operations::drop_schema operation("dodbm");

        auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
        REQUIRE(command.get_text() == "DROP SCHEMA `dodbm`");
    }

    // Table.
    SECTION("create_table")
    {
        std::vector<std::shared_ptr<dodbm::operations::add_column>> columns;

        {
            std::shared_ptr<dodbm::operations::add_column> column(new dodbm::operations::add_column("col1"));
            column->set_column_type(mocks::types::integer::name);

            columns.emplace_back(column);
        }

        {
            std::shared_ptr<dodbm::operations::add_column> column(new dodbm::operations::add_column("col2"));
            column->set_column_type(mocks::types::varchar::name);
            column->set_max_length(128);

            columns.emplace_back(column);
        }

        dodbm::operations::create_table operation("dbm");
        operation.set_columns(columns);
        operation.set_schema("do");

        SECTION("without options")
        {
            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "CREATE TABLE `do`.`dbm` (`col1` INT NOT NULL, `col2` VARCHAR(128) NOT NULL)");
        }
        SECTION("with options")
        {
            operation.set_collation(dodbm::collation(utf8mb4_unicode_ci::name, utf8mb4_unicode_ci::charset));
            operation.set_comment("Hello");
            operation.set_engine(dodbm::storage_engine(InnoDB::name));

            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "CREATE TABLE `do`.`dbm` (`col1` INT NOT NULL, `col2` VARCHAR(128) NOT NULL) ENGINE InnoDB CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci COMMENT 'Hello'");
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
            REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` ENGINE InnoDB CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci COMMENT 'Hello'");
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

    // Column.
    SECTION("add_column")
    {
        dodbm::operations::add_column operation("dodbm");
        operation.set_attribute(dodbm::column_attribute::unsigned_normal);
        operation.set_auto_incremented(true);
        operation.set_collation(dodbm::collation(utf8mb4_unicode_ci::name, utf8mb4_unicode_ci::charset));
        operation.set_comment("Hello");
        operation.set_default_value("dodbm");
        operation.set_nullable(true);
        operation.set_schema("do");
        operation.set_table("dbm");

        SECTION("without type")
        {
            REQUIRE_THROWS(generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper));
        }
        SECTION("ENUM")
        {
            operation.set_column_type("ENUM");
            operation.set_values({ "1", "2", "3" });

            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` ADD COLUMN `dodbm` ENUM('1', '2', '3') UNSIGNED CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci "
                                          "NULL DEFAULT 'dodbm' AUTO_INCREMENT COMMENT 'Hello'");
        }
        SECTION("INT")
        {
            operation.set_column_type(mocks::types::integer::name);

            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` ADD COLUMN `dodbm` INT UNSIGNED CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci "
                                          "NULL DEFAULT 'dodbm' AUTO_INCREMENT COMMENT 'Hello'");
        }
        SECTION("VARCHAR")
        {
            operation.set_column_type(mocks::types::varchar::name);
            operation.set_max_length(128);

            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` ADD COLUMN `dodbm` VARCHAR(128) UNSIGNED CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci "
                                          "NULL DEFAULT 'dodbm' AUTO_INCREMENT COMMENT 'Hello'");
        }
        SECTION("set_move_*")
        {
            operation.set_column_type(mocks::types::varchar::name);
            operation.set_max_length(128);

            SECTION("set_move_after")
            {
                operation.set_move_after("do");

                auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
                REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` ADD COLUMN `dodbm` VARCHAR(128) UNSIGNED CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci "
                                              "NULL DEFAULT 'dodbm' AUTO_INCREMENT COMMENT 'Hello' AFTER `do`");
            }
            SECTION("set_move_first")
            {
                operation.set_move_first();

                auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
                REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` ADD COLUMN `dodbm` VARCHAR(128) UNSIGNED CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci "
                                              "NULL DEFAULT 'dodbm' AUTO_INCREMENT COMMENT 'Hello' FIRST");
            }
        }
    }
    SECTION("alter_column")
    {
        dodbm::operations::alter_column operation("dodbm");
        operation.set_column_type(mocks::types::integer::name);
        operation.set_nullable(true);
        operation.set_table("dbm");

        auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
        REQUIRE(command.get_text() == "ALTER TABLE `dbm` MODIFY COLUMN `dodbm` INT NULL");
    }
    SECTION("drop_column")
    {
        dodbm::operations::drop_column operation("dodbm");
        operation.set_table("dbm");

        auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
        REQUIRE(command.get_text() == "ALTER TABLE `dbm` DROP COLUMN `dodbm`");
    }
    SECTION("rename_column")
    {
        dodbm::operations::rename_column operation("do");
        operation.set_new_name("dodbm");
        operation.set_table("dbm");

        auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
        REQUIRE(command.get_text() == "ALTER TABLE `dbm` RENAME COLUMN `do` TO `dodbm`");
    }

    //  Primary key.
    SECTION("add_primary_key")
    {
        dodbm::operations::add_primary_key operation("pk");
        operation.set_column("col1");
        operation.set_comment("Hello");
        operation.set_schema("do");
        operation.set_table("dbm");

        auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
        REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` ADD PRIMARY KEY `pk` (`col1`) COMMENT 'Hello'");
    }
    SECTION("drop_primary_key")
    {
        dodbm::operations::drop_primary_key operation;
        operation.set_schema("do");
        operation.set_table("dbm");

        auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
        REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` DROP PRIMARY KEY");
    }

    //  Foreign key.
    SECTION("add_foreign_key")
    {
        dodbm::operations::add_foreign_key operation("fk");
        operation.set_column("col1");
        operation.set_schema("do");
        operation.set_table("table1");

        operation.set_in_schema("do2");
        operation.set_from_table("table2");
        operation.set_on_column("col2");

        operation.set_on_delete(dodbm::constraint_action::cascade);
        operation.set_on_update(dodbm::constraint_action::cascade);

        auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
        REQUIRE(command.get_text() == "ALTER TABLE `do`.`table1` ADD FOREIGN KEY `fk` (`col1`) REFERENCES `do2`.`table2` (`col2`) ON DELETE CASCADE ON UPDATE CASCADE");
    }
    SECTION("drop_foreign_key")
    {
        dodbm::operations::drop_foreign_key operation("fk");
        operation.set_schema("do");
        operation.set_table("dbm");

        auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
        REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` DROP FOREIGN KEY `fk`");
    }

    //  Unique constraint.
    SECTION("add_unique_constraint")
    {
        dodbm::operations::add_unique_constraint operation("uc");
        operation.set_comment("Hello");
        operation.set_schema("do");
        operation.set_table("dbm");

        SECTION("Single column")
        {
            operation.set_columns({ "col1" });

            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` ADD UNIQUE `uc` (`col1`) COMMENT 'Hello'");
        }
        SECTION("Multiple columns")
        {
            operation.set_columns({ "col1", "col2", "col3" });

            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` ADD UNIQUE `uc` (`col1`, `col2`, `col3`) COMMENT 'Hello'");
        }
    }
    SECTION("drop_unique_constraint")
    {
        dodbm::operations::drop_unique_constraint operation("uc");
        operation.set_schema("do");
        operation.set_table("dbm");

        auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
        REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` DROP CONSTRAINT `uc`");
    }

    //  Index
    SECTION("create_index")
    {
        dodbm::operations::create_index operation("index");
        operation.set_comment("Hello");
        operation.set_schema("do");
        operation.set_table("dbm");

        SECTION("Single column")
        {
            operation.set_columns({ "col1" });

            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` ADD INDEX `index` (`col1`) COMMENT 'Hello'");
        }
        SECTION("Multiple columns")
        {
            operation.set_columns({ "col1", "col2", "col3" });

            auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
            REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` ADD INDEX `index` (`col1`, `col2`, `col3`) COMMENT 'Hello'");
        }
    }
    SECTION("drop_index")
    {
        dodbm::operations::drop_index operation("index");
        operation.set_schema("do");
        operation.set_table("dbm");

        auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
        REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` DROP INDEX `index`");
    }
    SECTION("rename_index")
    {
        dodbm::operations::rename_index operation("index");
        operation.set_new_name("new_name");
        operation.set_schema("do");
        operation.set_table("dbm");

        auto command = generator.generate(*reinterpret_cast<dodbm::operation*>(&operation), helper);
        REQUIRE(command.get_text() == "ALTER TABLE `do`.`dbm` RENAME INDEX `index` TO `new_name`");
    }
}