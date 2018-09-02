#pragma once

#include <string>

#include <dodbm/operation.hpp>

namespace dodbm
{
    namespace operations
    {
        class custom_sql : public operation
        {
        public:

            custom_sql(const std::string& sql);

            type get_type() const final;

            const std::string& get_sql() const;

        private:

            std::string m_sql;
        };
    }
}