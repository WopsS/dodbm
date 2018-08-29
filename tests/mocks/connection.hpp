#pragma once

#include <dodbm/connection.hpp>

namespace mocks
{
    class connection : public dodbm::connection
    {
    public:

        virtual void start_transaction() override;
        virtual void commit() override;
        virtual void rollback() override;

        virtual void execute_non_query(const std::string& text) override;
        virtual dodbm::db_result execute_query(const std::string& text) override;
    };
}