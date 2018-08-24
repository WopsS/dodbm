#pragma once

#include <dodbm/base_provider.hpp>
#include <dodbm/migration.hpp>

namespace dodbm
{
    class repository
    {
    public:

        repository(std::shared_ptr<base_provider> provider);
        ~repository() = default;

        template<typename T>
        void add()
        {
            // TODO: Remove typeid, get function name at compile time.
            m_migrations.emplace(typeid(T).name(), new T());
        }

        void run();

    private:

        std::shared_ptr<base_provider> m_provider;

        std::map<std::string, std::unique_ptr<migration>> m_migrations;
    };
}