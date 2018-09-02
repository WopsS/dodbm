#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/update_data.hpp>

#include <dodbm/builders/helpers/has_schema.hpp>
#include <dodbm/builders/helpers/has_table.hpp>

namespace dodbm
{
    namespace builders
    {
        class update_data : public builders::operation<operations::update_data>
            , public helpers::has_schema<update_data>
            , public helpers::has_table<update_data>
        {
        public:

            using operation::operation;

            template<typename T>
            const update_data& set(const std::string& column, const T& value) const
            {
                return set({ { column, value } });
            }

            const update_data& set(std::initializer_list<db_data> data) const;
        };
    }
}