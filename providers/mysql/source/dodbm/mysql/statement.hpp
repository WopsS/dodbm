#pragma once

#include <memory>
#include <string>
#include <vector>

#include <mysql.h>

#include <dodbm/db_result.hpp>
#include <dodbm/mysql/bind.hpp>

namespace dodbm
{
    namespace mysql
    {
        class statement
        {
        public:

            statement(MYSQL* mysql, const std::string& query);
            ~statement();

            void bind(const std::vector<db_value>& parameters);

            std::size_t execute(); 

            db_result query();

        private:

            MYSQL* m_mysql;

            MYSQL_STMT* m_stmt;

            std::vector<std::unique_ptr<mysql::bind>> m_binds;
        };
    }
}