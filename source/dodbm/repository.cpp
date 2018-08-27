#include <dodbm/repository.hpp>
#include <dodbm/exception.hpp>

dodbm::repository::repository(std::unique_ptr<provider> provider)
    : m_provider(std::move(provider))
{
    auto history = m_provider->get_history_repository();
    if (!history.exists())
    {
        history.create();
    }
}

void dodbm::repository::migrate()
{
    auto history = m_provider->get_history_repository();
    auto last_migration = history.get_last_applied_migration();

    auto begin = m_migrations.find(last_migration);
    if (begin == m_migrations.end())
    {
        begin = m_migrations.begin();
    }
    else
    {
        // Move to the next migration which is unapplied.
        ++begin;
    }

    for (auto i = begin; i != m_migrations.end(); ++i)
    {
        auto& name = i->first;
        auto& migration = i->second;

        auto operations = migration->get_up_operations();

        if (operations.empty())
        {
            throw dodbm::exception("Up operations for \"" + name + "\" is empty");
        }

        // TODO: Insert migration in history.
        //operations.emplace(history.get_insert_operation(name));

        auto generator = m_provider->get_generator();
        auto commands = generator.generate(operations);

        // TODO: Migrate.
    }
}

void dodbm::repository::rollback_to(const std::string& name)
{
    auto history = m_provider->get_history_repository();
    auto last_migration = history.get_last_applied_migration();

    auto rbegin = std::find_if(m_migrations.rbegin(), m_migrations.rend(), [&last_migration](const decltype(m_migrations)::value_type& it)
    {
        return it.first == last_migration;
    });

    auto rend = std::find_if(m_migrations.rbegin(), m_migrations.rend(), [&name](const decltype(m_migrations)::value_type& it) {
        return it.first == name;
    });

    for (auto i = rbegin; i != rend; ++i)
    {
        auto& name = i->first;
        auto& migration = i->second;

        auto operations = migration->get_down_operations();

        if (operations.empty())
        {
            throw dodbm::exception("Down operations for \"" + name + "\" is empty");
        }

        // TODO: Remove migration from history.
        //operations.emplace(history.get_delete_operation(name));

        auto generator = m_provider->get_generator();
        auto commands = generator.generate(operations);

        // TODO: Rollback.
    }
}
