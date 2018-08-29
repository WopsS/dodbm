#include <catch2/catch.hpp>

#include <dodbm/operations/alter_database.hpp>

TEST_CASE("Database operation", "[operations]")
{
    dodbm::operations::alter_database operation("dodbm");
    REQUIRE(operation.get_type() == dodbm::operation::type::alter_database);
}