#include <catch2/catch.hpp>

#include <dodbm/operations/create_index.hpp>
#include <dodbm/operations/drop_index.hpp>
#include <dodbm/operations/rename_index.hpp>

TEST_CASE("Index operations", "[operations]")
{
    using type = dodbm::operation::type;

    SECTION("create_index")
    {
        dodbm::operations::create_index operation;
        REQUIRE(operation.get_type() == type::create_index);
    }
    SECTION("drop_index")
    {
        dodbm::operations::drop_index operation("index");
        REQUIRE(operation.get_type() == type::drop_index);
    }
    SECTION("rename_index")
    {
        dodbm::operations::rename_index operation("index");
        REQUIRE(operation.get_type() == type::rename_index);
    }
}