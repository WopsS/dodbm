#pragma once

#include <dodbm/base_provider.hpp>
#include <dodbm/migration.hpp>
#include <dodbm/name_of.hpp>

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
            m_migrations.emplace(dodbm::name_of<T>(), new T());
        }

        void run();

    private:

        std::shared_ptr<base_provider> m_provider;

        std::map<std::string, std::unique_ptr<migration>> m_migrations;
    };
}