#pragma once

#include <memory>
#include <vector>

#include <dodbm/operation.hpp>

#include <dodbm/operations/add_column.hpp>

#include <dodbm/operations/helpers/has_collation.hpp>
#include <dodbm/operations/helpers/has_comment.hpp>
#include <dodbm/operations/helpers/has_engine.hpp>
#include <dodbm/operations/helpers/has_required_name.hpp>
#include <dodbm/operations/helpers/has_schema.hpp>

namespace dodbm
{
    namespace operations
    {
        class create_table : public operation
            , public helpers::has_collation
            , public helpers::has_comment
            , public helpers::has_engine
            , public helpers::has_required_name
            , public helpers::has_schema
        {
        public:

            using has_required_name::has_required_name;

            type get_type() const final;

            void set_columns(std::vector<std::shared_ptr<add_column>> columns);
            const std::vector<std::shared_ptr<add_column>>& get_columns() const;

        private:

            std::vector<std::shared_ptr<add_column>> m_columns;
        };
    }
}