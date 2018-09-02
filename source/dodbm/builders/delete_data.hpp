#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/delete_data.hpp>

#include <dodbm/builders/helpers/has_schema.hpp>

namespace dodbm
{
    namespace builders
    {
        class delete_data : public builders::operation<operations::delete_data>
            , public helpers::has_schema<delete_data>
        {
        public:

            using operation::operation;

            const delete_data& from(const std::string& table_name) const;
        };
    }
}