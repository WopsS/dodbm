#pragma once

#include <string>

#include <dodbm/operation.hpp>

namespace dodbm
{
    namespace operations
    {
        class drop_schema : public operation
        {
        public:

            drop_schema(const std::string& name);
            ~drop_schema() = default;

            type get_type() const final;

            const std::string& get_name() const;

        private:

            std::string m_name;
        };
    }
}