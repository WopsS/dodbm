#include <catch2/catch.hpp>

#include <dodbm/operations/alter_table.hpp>
#include <dodbm/operations/create_table.hpp>
#include <dodbm/operations/drop_table.hpp>
#include <dodbm/operations/rename_table.hpp>

TEST_CASE("Table operation", "[operations]")
{
    using type = dodbm::operation::type;

    SECTION("create_table")
    {
        dodbm::operations::create_table operation("dodbm");
        REQUIRE(operation.get_type() == type::create_table);
    }
    SECTION("drop_table")
    {
        dodbm::operations::drop_table operation("dodbm");
        REQUIRE(operation.get_type() == type::drop_table);
    }
    SECTION("alter_table")
    {
        dodbm::operations::alter_table operation("dodbm");
        REQUIRE(operation.get_type() == type::alter_table);
    }
    SECTION("rename_table")
    {
        dodbm::operations::rename_table operation("dodbm");
        REQUIRE(operation.get_type() == type::rename_table);
    }
}