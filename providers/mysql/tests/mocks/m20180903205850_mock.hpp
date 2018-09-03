#pragma once

#include <dodbm/migration.hpp>

namespace mocks
{
    class m20180903205850_mock : public dodbm::migration
    {
    protected:

        void up(dodbm::migration_builder& builder) final;
        void down(dodbm::migration_builder& builder) final;
    };
}