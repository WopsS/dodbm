#pragma once

#include <memory>
#include <queue>

#include <dodbm/operation.hpp>

#include <dodbm/builders/alter_database.hpp>

#include <dodbm/builders/ensure_schema.hpp>

#include <dodbm/builders/alter_table.hpp>
#include <dodbm/builders/create_table.hpp>
#include <dodbm/builders/drop_table.hpp>
#include <dodbm/builders/rename_table.hpp>

#include <dodbm/builders/add_column.hpp>
#include <dodbm/builders/alter_column.hpp>
#include <dodbm/builders/drop_column.hpp>
#include <dodbm/builders/rename_column.hpp>

#include <dodbm/builders/add_primary_key.hpp>
#include <dodbm/builders/drop_primary_key.hpp>

#include <dodbm/builders/add_foreign_key.hpp>
#include <dodbm/builders/drop_foreign_key.hpp>

#include <dodbm/builders/add_unique_constraint.hpp>
#include <dodbm/builders/drop_unique_constraint.hpp>

#include <dodbm/builders/create_index.hpp>
#include <dodbm/builders/drop_index.hpp>
#include <dodbm/builders/rename_index.hpp>

namespace dodbm
{
    class migration;

    namespace builders
    {
        class migration
        {
        public:

            migration() = default;
            ~migration() = default;

            builders::alter_database alter_database(const std::string& name);

            builders::ensure_schema ensure_schema(const std::string& name);
            void drop_schema(const std::string& name);

            builders::create_table create_table(const std::string& name);
            builders::drop_table drop_table(const std::string& name);
            builders::alter_table alter_table(const std::string& name);
            builders::rename_table rename_table(const std::string& name);

            template<typename T>
            builders::add_column add_column(const std::string& name)
            {
                std::shared_ptr<operations::add_column> operation(new operations::add_column(name));
                operation->set_column_type(T::name);

                m_operations.emplace(operation);
                return builders::add_column(operation);
            }

            template<typename T>
            builders::alter_column alter_column(const std::string& name)
            {
                std::shared_ptr<operations::alter_column> operation(new operations::alter_column(name));
                operation->set_column_type(T::name);

                m_operations.emplace(operation);
                return builders::alter_column(operation);
            }

            builders::drop_column drop_column(const std::string& name);
            builders::rename_column rename_column(const std::string& name);

            builders::add_primary_key add_primary_key(const std::string& name = "");
            builders::drop_primary_key drop_primary_key(const std::string& name = "");

            builders::add_foreign_key add_foreign_key(const std::string& name = "");
            builders::drop_foreign_key drop_foreign_key(const std::string& name);

            builders::add_unique_constraint add_unique_constraint(const std::string& name = "");
            builders::drop_unique_constraint drop_unique_constraint(const std::string& name);

            builders::create_index create_index(const std::string& name = "");
            builders::drop_index drop_index(const std::string& name);
            builders::rename_index rename_index(const std::string& name);

        private:

            friend class dodbm::migration;

            std::queue<std::shared_ptr<dodbm::operation>> operations;
        };
    }

    using migration_builder = builders::migration;
}