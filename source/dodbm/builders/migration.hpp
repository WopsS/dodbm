#pragma once

#include <dodbm/builders/alter_table.hpp>
#include <dodbm/builders/create_table.hpp>
#include <dodbm/builders/rename_table.hpp>

namespace dodbm
{
    class repository;

    namespace builders
    {
        class migration
        {
        public:

            migration() = default;
            ~migration() = default;

            builders::create_table create_table(const std::string& name);
            void drop_table(const std::string& name);
            builders::alter_table alter_table(const std::string& name);
            builders::rename_table rename_table(const std::string& name);

            void add_column(const std::string& name, const std::string& table);
            void drop_column(const std::string& name, const std::string& table);

            void alter_column(const std::string& name, const std::string& table);
            void rename_column(const std::string& name, const std::string& table);

            void add_primary_key(const std::string& name, const std::string& column, const std::string& table);
            void drop_primary_key(const std::string& name, const std::string& column, const std::string& table);

            void add_foreign_key(const std::string& name, const std::string& column, const std::string& table, const std::string& principal_name, const std::string& principal_column, const std::string& principal_table);
            void drop_foreign_key(const std::string& name, const std::string& column, const std::string& table, const std::string& principal_name, const std::string& principal_column, const std::string& principal_table);

            void add_unique_constraint(const std::string& name, const std::string& column, const std::string& table);
            void drop_unique_constraint(const std::string& name, const std::string& column, const std::string& table);

            void create_index(const std::string& name, std::initializer_list<std::string> columns, const std::string& table);
            void drop_index(const std::string& name, const std::string& table);
            void rename_index(const std::string& name, const std::string& table);

            void insert_data();
            void delete_data();
            void update_data();

        private:

            friend class dodbm::repository;

            std::queue<std::unique_ptr<operations::base_operation>> operations;
        };
    }

    using migration_builder = builders::migration;
}