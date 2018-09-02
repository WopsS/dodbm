#pragma once

#include <vector>

#include <dodbm/db_data.hpp>

namespace dodbm
{
    namespace operations
    {
        namespace helpers
        {
            class has_where_data
            {
            public:

                void set_where_data(std::vector<db_data> data);
                const std::vector<db_data>& get_where_data() const;

            protected:

                has_where_data() = default;
                virtual ~has_where_data() = default;

            private:

                std::vector<db_data> m_where_data;
            };
        }
    }
}