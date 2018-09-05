#pragma once

#include <mysql.h>

#include <dodbm/connection.hpp>

#include <dodbm/mysql/config.hpp>

namespace dodbm
{
    namespace mysql
    {
        class connection : public dodbm::connection
        {
        public:

            connection(const config& config);
            ~connection();

            void start_transaction() final;
            void commit() final;
            void rollback() final;

            void execute_non_query(const std::string& text) final;
            void execute_non_query(const std::string& text, const std::vector<db_value>& parameters) final;
            db_result execute_query(const std::string& text, const std::vector<db_value>& parameters = {}) final;

            std::string get_schema_name() const final;

        private:

            MYSQL* m_mysql;

            std::string m_schema;

            decltype(config::debug) debug;
        };
    }
}