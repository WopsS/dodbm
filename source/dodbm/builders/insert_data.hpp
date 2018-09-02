#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/insert_data.hpp>

#include <dodbm/builders/helpers/has_schema.hpp>
#include <dodbm/builders/helpers/has_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class insert_data : public builders::operation<operations::insert_data>
            , public helpers::has_schema<insert_data>
        {
        public:

            using operation::operation;

            const insert_data& in(const std::string& table_name) const;
        };
    }
}