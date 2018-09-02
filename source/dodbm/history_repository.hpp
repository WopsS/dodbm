#pragma once

#include <string>

#include <dodbm/connection.hpp>
#include <dodbm/sql_generator.hpp>

#include <dodbm/builders/insert_data.hpp>
#include <dodbm/builders/delete_data.hpp>

namespace dodbm
{
    class history_repository
    {
    public:

        history_repository() = default;
        virtual ~history_repository() = default;

        virtual bool exists(connection* connection, const sql_generator_helper& helper) const;

        virtual void create(connection* connection, const sql_generator& generator, const sql_generator_helper& helper);

        virtual const std::string get_last_applied_migration(connection* connection, const sql_generator_helper& helper) const;

        virtual std::shared_ptr<operations::insert_data> get_insert_operation(const std::string& migration_name);
        virtual std::shared_ptr<operations::delete_data> get_delete_operation(const std::string& migration_name);

    protected:

        virtual const std::string get_table_name() const;

        virtual const std::string get_id_column_name() const;
    };
}