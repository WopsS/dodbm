#pragma once

#include <dodbm/builders/operation.hpp>
#include <dodbm/operations/alter_database.hpp>

#include <dodbm/builders/helpers/has_collation.hpp>

namespace dodbm
{
    namespace builders
    {
        class alter_database : public builders::operation<operations::alter_database>
            , public helpers::has_collation<alter_database>
        {
        public:

            using operation::operation;
        };
    }
}