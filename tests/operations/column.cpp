#include <catch2/catch.hpp>

#include <dodbm/operations/add_column.hpp>
#include <dodbm/operations/alter_column.hpp>
#include <dodbm/operations/drop_column.hpp>
#include <dodbm/operations/rename_column.hpp>

TEST_CASE("Column operations", "[operations]")
{
    using type = dodbm::operation::type;

    SECTION("add_column")
    {
        dodbm::operations::add_column operation("dodbm");
        REQUIRE(operation.get_type() == type::add_column);
    }
    SECTION("alter_column")
    {
        dodbm::operations::alter_column operation("dodbm");
        REQUIRE(operation.get_type() == type::alter_column);
    }
    SECTION("drop_column")
    {
        dodbm::operations::drop_column operation("dodbm");
        REQUIRE(operation.get_type() == type::drop_column);
    }
    SECTION("rename_column")
    {
        dodbm::operations::rename_column operation("dodbm");
        REQUIRE(operation.get_type() == type::rename_column);
    }
}