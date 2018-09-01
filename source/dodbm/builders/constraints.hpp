#pragma once

#include <string>
#include <vector>

#include <dodbm/builders/add_foreign_key.hpp>
#include <dodbm/builders/add_primary_key.hpp>
#include <dodbm/builders/add_unique_constraint.hpp>

namespace dodbm
{
    namespace builders
    {
        class create_table;

        class constraints
        {
        public:

            builders::add_foreign_key foreign_key(const std::string& name = "");
            builders::add_primary_key primary_key(const std::string& name = "");
            builders::add_unique_constraint unique_constraint(const std::string& name = "");

        private:

            friend class create_table;

            std::shared_ptr<operations::add_primary_key> primary_key_;
            std::vector<std::shared_ptr<operations::add_foreign_key>> foreign_keys;
            std::vector<std::shared_ptr<operations::add_unique_constraint>> unique_constraints;
        };
    }

    using constraints_builder = builders::constraints;
}