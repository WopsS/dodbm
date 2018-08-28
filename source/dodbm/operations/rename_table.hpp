#pragma once

#include <dodbm/operation.hpp>

#include <dodbm/operations/helpers/has_name.hpp>
#include <dodbm/operations/helpers/has_schema.hpp>

namespace dodbm
{
    namespace operations
    {
        class rename_table : public operation
            , public helpers::has_name
            , public helpers::has_schema
        {
        public:

            using has_name::has_name;

            type get_type() const final;

            void set_new_name(const std::string& name);
            const std::string& get_new_name() const;

        private:

            std::string m_new_name;
        };
    }
}