#pragma once

#include <algorithm>
#include <map>
#include <memory>
#include <string>

#include <dodbm/migration.hpp>
#include <dodbm/name_of.hpp>
#include <dodbm/provider.hpp>

namespace dodbm
{
    class repository
    {
    public:

        repository(std::unique_ptr<provider> provider);
        ~repository() = default;

        template<typename T>
        void add()
        {
            static_assert(std::is_base_of<migration, T>::value, "T should extend \"dodbm::migration\"");
            m_migrations.emplace(dodbm::name_of<T>(), new T());
        }

        template<typename T>
        void rollback_to()
        {
            static_assert(std::is_base_of<migration, T>::value, "T should extend \"dodbm::migration\"");
            rollback_to(dodbm::name_of<T>());
        }

        void migrate();

    private:

        void rollback_to(const std::string& name);

        std::unique_ptr<provider> m_provider;

        std::map<std::string, std::unique_ptr<migration>> m_migrations;
    };
}