#pragma once

#include <memory>
#include <vector>

#include <dodbm/operation.hpp>

#include <dodbm/operations/add_column.hpp>
#include <dodbm/operations/add_primary_key.hpp>
#include <dodbm/operations/add_foreign_key.hpp>
#include <dodbm/operations/add_unique_constraint.hpp>

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

            void set_primary_key(std::shared_ptr<add_primary_key> primary_key);
            const std::shared_ptr<add_primary_key> get_primary_key() const;

            void set_foreign_keys(std::vector<std::shared_ptr<add_foreign_key>> primary_key);
            const std::vector<std::shared_ptr<add_foreign_key>>& get_foreign_keys() const;

            void set_unique_constraints(std::vector<std::shared_ptr<add_unique_constraint>> unique_constraints);
            const std::vector<std::shared_ptr<add_unique_constraint>>& get_unique_constraints() const;

        private:

            std::vector<std::shared_ptr<add_column>> m_columns;

            std::shared_ptr<add_primary_key> m_primary_key;
            std::vector<std::shared_ptr<add_foreign_key>> m_foreign_keys;
            std::vector<std::shared_ptr<add_unique_constraint>> m_unique_constraints;
        };
    }
}