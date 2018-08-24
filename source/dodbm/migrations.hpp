#pragma once

#include <dodbm/migrations/migration.hpp>
#include <dodbm/base_provider.hpp>

namespace dodbm
{
    class migrations
    {
    public:

        migrations(const base_provider& provider);
        ~migrations() = default;

        template<typename T>
        void add()
        {
            // TODO: Remove typeid, get function name at compile time.
            m_migrations.emplace(typeid(T).name(), new T());
        }

        void run();

    private:

        base_provider m_provider;

        std::map<std::string, std::unique_ptr<migration>> m_migrations;
    };
}