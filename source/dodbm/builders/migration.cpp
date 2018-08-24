#include <dodbm/dodbm.hpp>
#include <dodbm/builders/migration.hpp>
#include <dodbm/operations/drop_table.hpp>

dodbm::builders::create_table dodbm::migration_builder::create_table(const std::string& name)
{
    if (name.empty())
    {
        throw dodbm::exception("Table should have a name");
    }

    auto ptr = new operations::create_table(name);
    m_operations.emplace(ptr);

    return builders::create_table(ptr);
}

void dodbm::migration_builder::drop_table(const std::string& name)
{
    if (name.empty())
    {
        throw dodbm::exception("Table should have a name");
    }

    m_operations.emplace(new operations::drop_table(name));
}

dodbm::builders::alter_table dodbm::migration_builder::alter_table(const std::string& name)
{
    if (name.empty())
    {
        throw dodbm::exception("Table should have a name");
    }

    auto ptr = new operations::alter_table(name);
    m_operations.emplace(ptr);

    return builders::alter_table(ptr);
}

dodbm::builders::rename_table dodbm::migration_builder::rename_table(const std::string& name)
{
    if (name.empty())
    {
        throw dodbm::exception("Table should have a name");
    }

    auto ptr = new operations::rename_table(name);
    m_operations.emplace(ptr);

    return builders::rename_table(ptr);
}
