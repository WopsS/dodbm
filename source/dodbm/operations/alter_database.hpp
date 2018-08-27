#pragma once

#include <memory>

#include <dodbm/collation.hpp>
#include <dodbm/operation.hpp>

namespace dodbm
{
    namespace operations
    {
        class alter_database : public operation
        {
        public:

            alter_database(const std::string& name);
            ~alter_database() = default;

            type get_type() const final;

            const std::string& get_name() const;

            void set_collation(std::unique_ptr<collation> value);
            const collation& get_collation() const;

        private:

            std::string m_name;

            std::unique_ptr<collation> m_collation;
        };
    }
}