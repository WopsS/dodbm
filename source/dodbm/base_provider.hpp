#pragma once

namespace dodbm
{
    class base_provider
    {
    public:

        base_provider() = default;
        ~base_provider() = default;

        virtual void start_transaction() = 0;
        virtual void commit() = 0;
        virtual void rollback() = 0;
    };
}