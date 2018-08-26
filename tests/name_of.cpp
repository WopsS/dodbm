#include <catch2/catch.hpp>
#include <dodbm/name_of.hpp>

class M1_GlobalNamespace
{
};

namespace
{
    class M2_AnonymousNamespace
    {
    };
}

namespace ns1
{
    class M3_NamespaceLevel1
    {
    };

    namespace ns2
    {
        class M4_NamespaceLevel2
        {
        };

        class M5_NamespaceLevel2
        {
        public:

            class M6_InClass
            {
            };
        };
    }
}

TEST_CASE("name_of")
{
    CHECK(dodbm::name_of<M1_GlobalNamespace>() == "M1_GlobalNamespace");
    CHECK(dodbm::name_of<M2_AnonymousNamespace>() == "M2_AnonymousNamespace");
    CHECK(dodbm::name_of<ns1::M3_NamespaceLevel1>() == "M3_NamespaceLevel1");
    CHECK(dodbm::name_of<ns1::ns2::M4_NamespaceLevel2>() == "M4_NamespaceLevel2");
    CHECK(dodbm::name_of<ns1::ns2::M5_NamespaceLevel2::M6_InClass>() == "M6_InClass");
}