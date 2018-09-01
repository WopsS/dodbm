#include <catch2/catch.hpp>

#include <dodbm/operations/add_primary_key.hpp>
#include <dodbm/operations/drop_primary_key.hpp>

#include <dodbm/operations/add_foreign_key.hpp>
#include <dodbm/operations/drop_foreign_key.hpp>

#include <dodbm/operations/add_unique_constraint.hpp>
#include <dodbm/operations/drop_unique_constraint.hpp>

TEST_CASE("Constraints operations", "[operations]")
{
    using type = dodbm::operation::type;

    SECTION("add_primary_key")
    {
        dodbm::operations::add_primary_key operation;
        REQUIRE(operation.get_type() == type::add_primary_key);
    }
    SECTION("drop_primary_key")
    {
        dodbm::operations::drop_primary_key operation;
        REQUIRE(operation.get_type() == type::drop_primary_key);
    }
    SECTION("add_foreign_key")
    {
        dodbm::operations::add_foreign_key operation;
        REQUIRE(operation.get_type() == type::add_foreign_key);
    }
    SECTION("drop_foreign_key")
    {
        dodbm::operations::drop_foreign_key operation("fk");
        REQUIRE(operation.get_type() == type::drop_foreign_key);
    }
    SECTION("add_unique_constraint")
    {
        dodbm::operations::add_unique_constraint operation;
        REQUIRE(operation.get_type() == type::add_unique_constraint);
    }
    SECTION("drop_unique_constraint")
    {
        dodbm::operations::drop_unique_constraint operation("uc");
        REQUIRE(operation.get_type() == type::drop_unique_constraint);
    }
}