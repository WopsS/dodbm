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

        repository(std::shared_ptr<provider> provider);
        ~repository() = default;

        template<typename T>
        void add()
        {
            static_assert(std::is_base_of<migration, T>::value, "T should extend \"dodbm::migration\"");
            m_migrations.emplace(dodbm::name_of<T>(), new T());
        }

        template<typename T>
        void rollback()
        {
            static_assert(std::is_base_of<migration, T>::value, "T should extend \"dodbm::migration\"");
            rollback(dodbm::name_of<T>());
        }

        template<typename T>
        void rollback_to()
        {
            static_assert(std::is_base_of<migration, T>::value, "T should extend \"dodbm::migration\"");
            rollback_to(dodbm::name_of<T>());
        }

        template<typename Collation>
        void set_default_collation()
        {
            collation::set_default(Collation::name, Collation::charset);
        }

        void migrate();

    private:

        void rollback(const std::string& name);

        void rollback(const std::string& name, migration* migration);

        void rollback_to(const std::string& name);

        std::shared_ptr<provider> m_provider;

        std::map<std::string, std::unique_ptr<migration>> m_migrations;
    };
}