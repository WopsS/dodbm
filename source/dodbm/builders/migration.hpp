#pragma once

#include <memory>
#include <queue>

#include <dodbm/operation.hpp>

#include <dodbm/builders/alter_database.hpp>

#include <dodbm/builders/alter_table.hpp>
#include <dodbm/builders/create_table.hpp>
#include <dodbm/builders/drop_table.hpp>
#include <dodbm/builders/rename_table.hpp>

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

            builders::alter_database alter_database(const std::string& name);

            builders::create_table create_table(const std::string& name);
            builders::drop_table drop_table(const std::string& name);
            builders::alter_table alter_table(const std::string& name);
            builders::rename_table rename_table(const std::string& name);

        private:

            std::queue<std::shared_ptr<dodbm::operation>> m_operations;
        };
    }

    using migration_builder = builders::migration;
}