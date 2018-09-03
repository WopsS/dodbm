#pragma once

#include <mysql.h>

namespace dodbm
{
    namespace mysql
    {
        class result_metadata
        {
        public:

            result_metadata(MYSQL_STMT* stmt);
            result_metadata(const result_metadata&) = delete;
            result_metadata(result_metadata&&) = delete;

            ~result_metadata();

            result_metadata& operator=(const result_metadata&) = delete;
            result_metadata& operator=(result_metadata&&) = delete;

            MYSQL_RES* get() const;

        private:

            MYSQL_RES* m_result;
        };
    }
}