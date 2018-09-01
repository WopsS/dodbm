#pragma once

#include <dodbm/builders/add_column.hpp>

namespace dodbm
{
    namespace builders
    {
        class create_table;
        class columns
        {
        public:

            template<typename T>
            builders::add_column add(const std::string& name)
            {
                std::shared_ptr<operations::add_column> operation(new operations::add_column(name));
                operation->set_column_type(T::name);

                columns.emplace_back(operation);
                return builders::add_column(operation);
            }

        private:

            friend class create_table;

            std::vector<std::shared_ptr<operations::add_column>> columns;
        };
    }

    using columns_builder = builders::columns;
}