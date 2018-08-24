#pragma once

namespace dodbm
{
    namespace operations
    {
        class rename_table : public base_operation
        {
        public:

            rename_table(const std::string& name);
            ~rename_table() = default;

            const std::string compile() const final;

            void set_new_name(const std::string& name);

        private:

            std::string m_name;

            std::string m_new_name;
        };
    }
}