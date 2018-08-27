#pragma once

#include <string>

namespace dodbm
{
    class history_repository
    {
    public:

        history_repository() = default;
        virtual ~history_repository() = default;

        bool exists() const;

        void create();

        const std::string get_last_applied_migration() const;

        void get_insert_operation(const std::string& name);
        void get_delete_operation(const std::string& name);
    };
}