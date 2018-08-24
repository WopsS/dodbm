#pragma once

#include <dodbm/builders/migration.hpp>

namespace dodbm
{
    class migration
    {
    public:

        migration() = default;
        ~migration() = default;

        virtual void build(migration_builder& builder) = 0;
    };
}