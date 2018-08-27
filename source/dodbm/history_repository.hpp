#pragma once

#include <string>

#include <dodbm/connection.hpp>
#include <dodbm/sql_generator_helper.hpp>

namespace dodbm
{
    class history_repository
    {
    public:

        history_repository() = default;
        virtual ~history_repository() = default;

        bool exists() const;

        void create();

        virtual const std::string get_last_applied_migration(connection* connection, const sql_generator_helper& helper) const;

        virtual void get_insert_operation(const std::string& table_name);
        virtual void get_delete_operation(const std::string& table_name);

    protected:

        virtual const std::string get_table_name() const;

        virtual const std::string get_id_column_name() const;
    };
}