#pragma once

#include <dodbm/builders/operation.hpp>

#include <dodbm/builders/alter_table.hpp>
#include <dodbm/builders/create_table.hpp>
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

            create_table create_table(const std::string& name);
            void drop_table(const std::string& name);
            alter_table alter_table(const std::string& name);
            rename_table rename_table(const std::string& name);

        private:

            std::queue<std::unique_ptr<operations::base_operation>> m_operations;
        };
    }

    using migration_builder = builders::migration;
}