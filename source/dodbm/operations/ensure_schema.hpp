#pragma once

#include <dodbm/collation.hpp>
#include <dodbm/operation.hpp>

namespace dodbm
{
    namespace operations
    {
        class ensure_schema : public operation
        {
        public:

            ensure_schema(const std::string& name);
            ~ensure_schema() = default;

            type get_type() const final;

            const std::string& get_name() const;

            void set_collation(collation value);
            const collation& get_collation() const;

        private:

            std::string m_name;

            collation m_collation;
        };
    }
}