#pragma once

#include <vector>

#include <dodbm/db_data.hpp>
#include <dodbm/operation.hpp>

#include <dodbm/operations/helpers/has_schema.hpp>
#include <dodbm/operations/helpers/has_table.hpp>

namespace dodbm
{
    namespace operations
    {
        class insert_data : public operation
            , public helpers::has_schema
            , public helpers::has_table
        {
        public:
            
            insert_data(std::vector<db_data> data);

            type get_type() const final;

            const std::vector<db_data>& get_data() const;

        private:

            std::vector<db_data> m_data;
        };
    }
}