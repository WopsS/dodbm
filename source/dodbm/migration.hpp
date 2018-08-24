#pragma once

#include <dodbm/builders/migration_builder.hpp>

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