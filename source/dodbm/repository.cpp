#include <dodbm/repository.hpp>

#include <dodbm/command_executor.hpp>
#include <dodbm/exception.hpp>

dodbm::repository::repository(std::unique_ptr<provider> provider)
    : m_provider(std::move(provider))
{
    auto connection = m_provider->get_connection();
    auto history = m_provider->get_history_repository();
    auto helper = m_provider->get_sql_generator_helper();

    if (!history.exists(connection, helper))
    {
        auto generator = m_provider->get_sql_generator();
        history.create(connection, generator, helper);
    }
}

void dodbm::repository::migrate()
{
    auto connection = m_provider->get_connection();
    auto history = m_provider->get_history_repository();
    auto helper = m_provider->get_sql_generator_helper();
    auto last_migration = history.get_last_applied_migration(connection, helper);

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
        const auto& name = i->first;
        const auto& migration = i->second;

        auto operations = migration->get_up_operations();

        if (operations.empty())
        {
            throw dodbm::exception("Up operations for \"" + name + "\" is empty");
        }

        operations.emplace(history.get_insert_operation(name));

        auto generator = m_provider->get_sql_generator();
        auto commands = generator.generate(operations, helper);

        connection->start_transaction();

        try
        {
            command_executor executor(connection);
            executor.execute(std::move(commands));

            connection->commit();
        }
        catch (dodbm::exception)
        {
            connection->rollback();
            throw;
        }
    }
}

void dodbm::repository::rollback(const std::string& name)
{
    auto it = m_migrations.find(name);
    if (it != m_migrations.end())
    {
        const auto& name = it->first;
        const auto& migration = it->second;

        rollback(name, migration.get());
    }
}

void dodbm::repository::rollback(const std::string& name, migration* migration)
{
    auto connection = m_provider->get_connection();
    auto helper = m_provider->get_sql_generator_helper();

    auto operations = migration->get_down_operations();

    if (operations.empty())
    {
        throw dodbm::exception("Down operations for \"" + name + "\" is empty");
    }

    auto history = m_provider->get_history_repository();
    operations.emplace(history.get_delete_operation(name));

    auto generator = m_provider->get_sql_generator();
    auto commands = generator.generate(operations, helper);

    connection->start_transaction();

    try
    {
        command_executor executor(connection);
        executor.execute(std::move(commands));

        connection->commit();
    }
    catch (dodbm::exception ex)
    {
        connection->rollback();
        throw;
    }
}

void dodbm::repository::rollback_to(const std::string& name)
{
    auto connection = m_provider->get_connection();
    auto history = m_provider->get_history_repository();
    auto helper = m_provider->get_sql_generator_helper();
    auto last_migration = history.get_last_applied_migration(connection, helper);

    auto rbegin = std::find_if(m_migrations.rbegin(), m_migrations.rend(), [&last_migration](const decltype(m_migrations)::value_type& it) {
        return it.first == last_migration;
    });

    if (rbegin == m_migrations.rend())
    {
        rbegin = m_migrations.rbegin();
    }

    auto rend = std::find_if(m_migrations.rbegin(), m_migrations.rend(), [&name](const decltype(m_migrations)::value_type& it) {
        return it.first == name;
    });

    for (auto it = rbegin; it != rend; it++)
    {
        const auto& name = it->first;
        const auto& migration = it->second;

        rollback(name, migration.get());
    }
}