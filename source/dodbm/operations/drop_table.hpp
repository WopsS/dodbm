#pragma once

namespace dodbm
{
    namespace operations
    {
        class drop_table : public base_operation
        {
        public:

            drop_table(const std::string& name);
            ~drop_table() = default;

            const std::string compile() const final;

        private:

            std::string m_name;
        };
    }
}