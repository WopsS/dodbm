#include <catch2/catch.hpp>

#include <dodbm/operations/drop_schema.hpp>
#include <dodbm/operations/ensure_schema.hpp>

TEST_CASE("Schema operations", "[operations]")
{
    using type = dodbm::operation::type;

    SECTION("ensure_schema")
    {
        dodbm::operations::ensure_schema operation("dodbm");
        REQUIRE(operation.get_type() == type::ensure_schema);
    }
    SECTION("drop_schema")
    {
        dodbm::operations::drop_schema operation("dodbm");
        REQUIRE(operation.get_type() == type::drop_schema);
    }
}