#include <catch2/catch.hpp>

#include <dodbm/operations/custom_sql.hpp>

TEST_CASE("Custom SQL operation", "[operations]")
{
    using type = dodbm::operation::type;

    SECTION("custom_sql")
    {
        dodbm::operations::custom_sql operation("mock");
        REQUIRE(operation.get_type() == type::custom_sql);
    }
}