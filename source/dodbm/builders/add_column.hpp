#pragma once

#include <dodbm/builders/column.hpp>
#include <dodbm/operations/add_column.hpp>

namespace dodbm
{
    namespace builders
    {
        class add_column : public builders::column<add_column, operations::add_column>
        {
        public:

            using column::column;
        };
    }
}