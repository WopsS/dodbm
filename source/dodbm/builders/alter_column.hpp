#pragma once

#include <dodbm/builders/column.hpp>
#include <dodbm/operations/alter_column.hpp>

namespace dodbm
{
    namespace builders
    {
        class alter_column : public builders::column<alter_column, operations::alter_column>
        {
        public:

            using column::column;
        };
    }
}