#pragma once

#include <memory>
#include <queue>

#include <dodbm/command.hpp>
#include <dodbm/operation.hpp>
#include <dodbm/sql_generator_helper.hpp>

#include <dodbm/operations/alter_database.hpp>

#include <dodbm/operations/alter_table.hpp>
#include <dodbm/operations/create_table.hpp>
#include <dodbm/operations/drop_table.hpp>
#include <dodbm/operations/rename_table.hpp>

namespace dodbm
{
    class sql_generator
    {
    public:

        sql_generator() = default;
        virtual ~sql_generator() = default;

        command generate(operation& operation, const sql_generator_helper& helper);
        std::queue<command> generate(std::queue<std::shared_ptr<operation>> operations, const sql_generator_helper& helper);

    protected:

        virtual command generate(const operations::alter_database& operation, const sql_generator_helper& helper);

        virtual command generate(const operations::alter_table& operation, const sql_generator_helper& helper);
        virtual command generate(const operations::create_table& operation, const sql_generator_helper& helper);
        virtual command generate(const operations::drop_table& operation, const sql_generator_helper& helper);
        virtual command generate(const operations::rename_table& operation, const sql_generator_helper& helper);

        virtual void generate_table_options(command& command, const sql_generator_helper& helper, const std::string& engine, const collation& collation, const std::string& comment);
    };
}