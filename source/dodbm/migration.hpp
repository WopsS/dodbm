#pragma once

#include <dodbm/builders/migration.hpp>

namespace dodbm
{
    class migration
    {
    public:

        migration() = default;
        ~migration() = default;

        std::queue<std::shared_ptr<operation>> get_up_operations();

        std::queue<std::shared_ptr<operation>> get_down_operations();

    protected:

        virtual void up(dodbm::migration_builder& builder) = 0;

        virtual void down(dodbm::migration_builder& builder) = 0;
    };
}