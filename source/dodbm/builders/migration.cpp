#include <dodbm/builders/migration.hpp>
#include <dodbm/exception.hpp>

#include <dodbm/operations/drop_schema.hpp>

dodbm::builders::alter_database dodbm::builders::migration::alter_database(const std::string& name)
{
    std::shared_ptr<operations::alter_database> ptr(new operations::alter_database(name));
    operations.emplace(ptr);

    return builders::alter_database(ptr);
}

dodbm::builders::ensure_schema dodbm::builders::migration::ensure_schema(const std::string& name)
{
    std::shared_ptr<operations::ensure_schema> ptr(new operations::ensure_schema(name));
    operations.emplace(ptr);

    return builders::ensure_schema(ptr);
}

void dodbm::builders::migration::drop_schema(const std::string& name)
{
    operations.emplace(new operations::drop_schema(name));
}

dodbm::builders::create_table dodbm::builders::migration::create_table(const std::string& name)
{
    std::shared_ptr<operations::create_table> ptr(new operations::create_table(name));
    operations.emplace(ptr);
    
    return builders::create_table(ptr);
}

dodbm::builders::drop_table dodbm::builders::migration::drop_table(const std::string& name)
{
    std::shared_ptr<operations::drop_table> ptr(new operations::drop_table(name));
    operations.emplace(ptr);

    return builders::drop_table(ptr);
}

dodbm::builders::alter_table dodbm::builders::migration::alter_table(const std::string& name)
{
    std::shared_ptr<operations::alter_table> ptr(new operations::alter_table(name));
    operations.emplace(ptr);

    return builders::alter_table(ptr);
}

dodbm::builders::rename_table dodbm::builders::migration::rename_table(const std::string& name)
{
    std::shared_ptr<operations::rename_table> ptr(new operations::rename_table(name));
    operations.emplace(ptr);

    return builders::rename_table(ptr);
}

dodbm::builders::drop_column dodbm::builders::migration::drop_column(const std::string& name)
{
    std::shared_ptr<operations::drop_column> ptr(new operations::drop_column(name));
    operations.emplace(ptr);

    return builders::drop_column(ptr);
}

dodbm::builders::rename_column dodbm::builders::migration::rename_column(const std::string& name)
{
    std::shared_ptr<operations::rename_column> ptr(new operations::rename_column(name));
    operations.emplace(ptr);

    return builders::rename_column(ptr);
}

dodbm::builders::add_primary_key dodbm::builders::migration::add_primary_key(const std::string& name)
{
    std::shared_ptr<operations::add_primary_key> ptr(new operations::add_primary_key(name));
    operations.emplace(ptr);

    return builders::add_primary_key(ptr);
}

dodbm::builders::drop_primary_key dodbm::builders::migration::drop_primary_key(const std::string& name)
{
    std::shared_ptr<operations::drop_primary_key> ptr(new operations::drop_primary_key(name));
    operations.emplace(ptr);

    return builders::drop_primary_key(ptr);
}

dodbm::builders::add_foreign_key dodbm::builders::migration::add_foreign_key(const std::string& name)
{
    std::shared_ptr<operations::add_foreign_key> ptr(new operations::add_foreign_key(name));
    operations.emplace(ptr);

    return builders::add_foreign_key(ptr);
}

dodbm::builders::drop_foreign_key dodbm::builders::migration::drop_foreign_key(const std::string& name)
{
    std::shared_ptr<operations::drop_foreign_key> ptr(new operations::drop_foreign_key(name));
    operations.emplace(ptr);

    return builders::drop_foreign_key(ptr);
}

dodbm::builders::add_unique_constraint dodbm::builders::migration::add_unique_constraint(const std::string& name)
{
    std::shared_ptr<operations::add_unique_constraint> ptr(new operations::add_unique_constraint(name));
    operations.emplace(ptr);

    return builders::add_unique_constraint(ptr);
}

dodbm::builders::drop_unique_constraint dodbm::builders::migration::drop_unique_constraint(const std::string& name)
{
    std::shared_ptr<operations::drop_unique_constraint> ptr(new operations::drop_unique_constraint(name));
    operations.emplace(ptr);

    return builders::drop_unique_constraint(ptr);
}

dodbm::builders::create_index dodbm::builders::migration::create_index(const std::string& name)
{
    std::shared_ptr<operations::create_index> ptr(new operations::create_index(name));
    operations.emplace(ptr);

    return builders::create_index(ptr);
}

dodbm::builders::drop_index dodbm::builders::migration::drop_index(const std::string& name)
{
    std::shared_ptr<operations::drop_index> ptr(new operations::drop_index(name));
    operations.emplace(ptr);

    return builders::drop_index(ptr);
}

dodbm::builders::rename_index dodbm::builders::migration::rename_index(const std::string& name)
{
    std::shared_ptr<operations::rename_index> ptr(new operations::rename_index(name));
    operations.emplace(ptr);

    return builders::rename_index(ptr);
}
