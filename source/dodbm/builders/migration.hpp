#pragma once

#include <queue>

#include <dodbm/operation.hpp>

namespace dodbm
{
    namespace builders
    {
        class migration
        {
        public:

            migration() = default;
            ~migration() = default;

            std::queue<operation> get_operations() const;

        private:

            std::queue<operation> m_operations;
        };
    }

    using migration_builder = builders::migration;
}