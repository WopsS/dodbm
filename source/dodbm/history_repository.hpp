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

        void insert_migration(const std::string& name);
        void delete_migration(const std::string& name);
    };
}