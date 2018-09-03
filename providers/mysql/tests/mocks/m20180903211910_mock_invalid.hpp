#pragma once

#include <dodbm/migration.hpp>

namespace mocks
{
    class m20180903211910_mock_invalid : public dodbm::migration
    {
    protected:

        void up(dodbm::migration_builder& builder) final;
        void down(dodbm::migration_builder& builder) final;
    };
}