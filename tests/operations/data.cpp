#include <catch2/catch.hpp>

#include <dodbm/operations/insert_data.hpp>
#include <dodbm/operations/delete_data.hpp>
#include <dodbm/operations/update_data.hpp>

TEST_CASE("Data operations", "[operations]")
{
    using type = dodbm::operation::type;

    SECTION("insert_data")
    {
        dodbm::operations::insert_data operation({});
        REQUIRE(operation.get_type() == type::insert_data);
    }
    SECTION("delete_data")
    {
        dodbm::operations::delete_data operation;
        REQUIRE(operation.get_type() == type::delete_data);
    }
    SECTION("update_data")
    {
        dodbm::operations::update_data operation;
        REQUIRE(operation.get_type() == type::update_data);
    }
}