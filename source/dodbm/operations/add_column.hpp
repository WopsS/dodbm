#pragma once

#include <dodbm/operation.hpp>
#include <dodbm/operations/helpers/column.hpp>

namespace dodbm
{
    namespace operations
    {
        class add_column : public operation
            , public helpers::column
        {
        public:

            using column::column;

            type get_type() const final;
        };
    }
}