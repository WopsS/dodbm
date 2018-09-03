#pragma once

#include <memory>
#include <queue>

#include <dodbm/command.hpp>
#include <dodbm/operation.hpp>
#include <dodbm/sql_generator_helper.hpp>

#include <dodbm/operations/alter_database.hpp>

#include <dodbm/operations/drop_schema.hpp>
#include <dodbm/operations/ensure_schema.hpp>

#include <dodbm/operations/alter_table.hpp>
#include <dodbm/operations/create_table.hpp>
#include <dodbm/operations/drop_table.hpp>
#include <dodbm/operations/rename_table.hpp>

#include <dodbm/operations/add_column.hpp>
#include <dodbm/operations/alter_column.hpp>
#include <dodbm/operations/drop_column.hpp>
#include <dodbm/operations/rename_column.hpp>

#include <dodbm/operations/add_primary_key.hpp>
#include <dodbm/operations/drop_primary_key.hpp>

#include <dodbm/operations/add_foreign_key.hpp>
#include <dodbm/operations/drop_foreign_key.hpp>

#include <dodbm/operations/add_unique_constraint.hpp>
#include <dodbm/operations/drop_unique_constraint.hpp>

#include <dodbm/operations/create_index.hpp>
#include <dodbm/operations/drop_index.hpp>
#include <dodbm/operations/rename_index.hpp>

#include <dodbm/operations/insert_data.hpp>
#include <dodbm/operations/delete_data.hpp>
#include <dodbm/operations/update_data.hpp>

#include <dodbm/operations/custom_sql.hpp>

namespace dodbm
{
    class sql_generator
    {
    public:

        sql_generator() = default;
        virtual ~sql_generator() = default;

        command generate(operation& operation, const sql_generator_helper& helper) const;
        std::queue<command> generate(std::queue<std::shared_ptr<operation>> operations, const sql_generator_helper& helper) const;

    protected:

        virtual command generate(const operations::alter_database& operation, const sql_generator_helper& helper) const;

        virtual command generate(const operations::drop_schema& operation, const sql_generator_helper& helper) const;
        virtual command generate(const operations::ensure_schema& operation, const sql_generator_helper& helper) const;

        virtual command generate(const operations::alter_table& operation, const sql_generator_helper& helper) const;
        virtual command generate(const operations::create_table& operation, const sql_generator_helper& helper) const;
        virtual command generate(const operations::drop_table& operation, const sql_generator_helper& helper) const;
        virtual command generate(const operations::rename_table& operation, const sql_generator_helper& helper) const;

        virtual command generate(const operations::add_column& operation, const sql_generator_helper& helper) const;
        virtual command generate(const operations::alter_column& operation, const sql_generator_helper& helper) const;
        virtual command generate(const operations::drop_column& operation, const sql_generator_helper& helper) const;
        virtual command generate(const operations::rename_column& operation, const sql_generator_helper& helper) const;

        virtual command generate(const operations::add_primary_key& operation, const sql_generator_helper& helper) const;
        virtual command generate(const operations::drop_primary_key& operation, const sql_generator_helper& helper) const;

        virtual command generate(const operations::add_foreign_key& operation, const sql_generator_helper& helper) const;
        virtual command generate(const operations::drop_foreign_key& operation, const sql_generator_helper& helper) const;

        virtual command generate(const operations::add_unique_constraint& operation, const sql_generator_helper& helper) const;
        virtual command generate(const operations::drop_unique_constraint& operation, const sql_generator_helper& helper) const;

        virtual command generate(const operations::create_index& operation, const sql_generator_helper& helper) const;
        virtual command generate(const operations::drop_index& operation, const sql_generator_helper& helper) const;
        virtual command generate(const operations::rename_index& operation, const sql_generator_helper& helper) const;

        virtual command generate(const operations::insert_data& operation, const sql_generator_helper& helper) const;
        virtual command generate(const operations::delete_data& operation, const sql_generator_helper& helper) const;
        virtual command generate(const operations::update_data& operation, const sql_generator_helper& helper) const;

        virtual command generate(const operations::custom_sql& operation, const sql_generator_helper& helper) const;

        virtual void generate_column(command& command, const sql_generator_helper& helper, const std::string& name, const std::string& type, size_t max_length, uint8_t decimals,
                                     const std::vector<std::string>& values, const db_value& default_value, const collation& collation, const dodbm::column_attribute attribute,
                                     bool is_nullable, bool is_auto_incremented, const std::string& comment, bool move_first = false, const std::string& move_after = "") const;

        virtual void generate_column_assignment(command& command, const sql_generator_helper& helper, const std::string& name, const db_value& value) const;

        virtual void generate_column_list(command& command, const sql_generator_helper& helper, const std::vector<std::string>& columns) const;

        virtual void generate_where(command& command, const sql_generator_helper& helper, const std::vector<dodbm::db_data>& data) const;

        virtual void generate_collation(command& command, const collation& collation) const;

        virtual void generate_comment(command& command, const sql_generator_helper& helper, const std::string& comment) const;

        virtual void generate_table_options(command& command, const sql_generator_helper& helper, const std::string& engine, const collation& collation, const std::string& comment) const;

        virtual void generate_primary_key(command& command, const sql_generator_helper& helper, const std::string& name, const std::string& column, const std::string& comment) const;

        virtual void generate_foreign_key(command& command, const sql_generator_helper& helper, const std::string& name, const std::string& column, const std::string& in_schema,
                                          const std::string& from_table, const std::string& on_column, const std::string& on_delete, const std::string& on_update) const;

        virtual void generate_unique_constraint(command& command, const sql_generator_helper& helper, const std::string& name, const std::vector<std::string>& columns, const std::string& comment) const;
    };
}