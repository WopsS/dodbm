#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/alter_table.hpp>

#include <dodbm/builders/helpers/has_collation.hpp>
#include <dodbm/builders/helpers/has_comment.hpp>
#include <dodbm/builders/helpers/has_engine.hpp>
#include <dodbm/builders/helpers/has_schema.hpp>

namespace dodbm
{
    namespace builders
    {
        class alter_table : public builders::operation<operations::alter_table>
            , public helpers::has_collation<alter_table>
            , public helpers::has_comment<alter_table>
            , public helpers::has_engine<alter_table>
            , public helpers::has_schema<alter_table>
        {
        public:

            using operation::operation;
        };
    }
}