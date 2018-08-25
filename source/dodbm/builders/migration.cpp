#include <dodbm/stdafx.hpp>
#include <dodbm/builders/migration.hpp>
#include <dodbm/operations/drop_table.hpp>

dodbm::builders::create_table dodbm::builders::migration::create_table(const std::string& name)
{
    if (name.empty())
    {
        throw dodbm::exception("Table should have a name");
    }

    auto ptr = new operations::create_table(name);
    operations.emplace(ptr);

    return builders::create_table(ptr);
}

void dodbm::builders::migration::drop_table(const std::string& name)
{
    if (name.empty())
    {
        throw dodbm::exception("Table should have a name");
    }

    operations.emplace(new operations::drop_table(name));
}

dodbm::builders::alter_table dodbm::builders::migration::alter_table(const std::string& name)
{
    if (name.empty())
    {
        throw dodbm::exception("Table should have a name");
    }

    auto ptr = new operations::alter_table(name);
    operations.emplace(ptr);

    return builders::alter_table(ptr);
}

dodbm::builders::rename_table dodbm::builders::migration::rename_table(const std::string& name)
{
    if (name.empty())
    {
        throw dodbm::exception("Table should have a name");
    }

    auto ptr = new operations::rename_table(name);
    operations.emplace(ptr);

    return builders::rename_table(ptr);
}
