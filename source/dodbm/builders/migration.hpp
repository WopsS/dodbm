#pragma once

#include <memory>
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

            std::queue<std::shared_ptr<dodbm::operation>> get_operations() const;

        private:

            std::queue<std::shared_ptr<dodbm::operation>> m_operations;
        };
    }

    using migration_builder = builders::migration;
}