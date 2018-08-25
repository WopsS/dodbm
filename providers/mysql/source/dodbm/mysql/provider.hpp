#pragma once

#include <functional>
#include <string>

#include <dodbm/mysql/config.hpp>
#include <dodbm/base_provider.hpp>

namespace dodbm
{
    namespace mysql
    {
        class provider : public base_provider
        {
        public:

            provider(const config& config);
            ~provider();

            void start_transaction() final;
            void commit() final;
            void rollback() final;

            std::string compile(operations::alter_table* operation) final;
            std::string compile(operations::create_table* operation) final;
            std::string compile(operations::drop_table* operation) final;
            std::string compile(operations::rename_table* operation) final;

            bool execute(const std::string& sql) final;
        };
    }
}