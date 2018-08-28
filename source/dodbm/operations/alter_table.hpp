#pragma once

#include <dodbm/operation.hpp>

#include <dodbm/operations/helpers/has_collation.hpp>
#include <dodbm/operations/helpers/has_comment.hpp>
#include <dodbm/operations/helpers/has_engine.hpp>
#include <dodbm/operations/helpers/has_name.hpp>
#include <dodbm/operations/helpers/has_schema.hpp>

namespace dodbm
{
    namespace operations
    {
        class alter_table : public operation
            , public helpers::has_collation
            , public helpers::has_comment
            , public helpers::has_engine
            , public helpers::has_name
            , public helpers::has_schema
        {
        public:

            using has_name::has_name;

            type get_type() const final;
        };
    }
}