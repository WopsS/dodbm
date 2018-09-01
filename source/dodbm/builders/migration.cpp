#include <dodbm/builders/migration.hpp>
#include <dodbm/exception.hpp>

#include <dodbm/operations/drop_schema.hpp>

std::queue<std::shared_ptr<dodbm::operation>> dodbm::builders::migration::get_operations() const
{
    return m_operations;
}

dodbm::builders::alter_database dodbm::builders::migration::alter_database(const std::string& name)
{
    std::shared_ptr<operations::alter_database> ptr(new operations::alter_database(name));
    m_operations.emplace(ptr);

    return builders::alter_database(ptr);
}

dodbm::builders::ensure_schema dodbm::builders::migration::ensure_schema(const std::string& name)
{
    std::shared_ptr<operations::ensure_schema> ptr(new operations::ensure_schema(name));
    m_operations.emplace(ptr);

    return builders::ensure_schema(ptr);
}

void dodbm::builders::migration::drop_schema(const std::string& name)
{
    m_operations.emplace(new operations::drop_schema(name));
}

dodbm::builders::create_table dodbm::builders::migration::create_table(const std::string& name)
{
    std::shared_ptr<operations::create_table> ptr(new operations::create_table(name));
    m_operations.emplace(ptr);
    
    return builders::create_table(ptr);
}

dodbm::builders::drop_table dodbm::builders::migration::drop_table(const std::string& name)
{
    std::shared_ptr<operations::drop_table> ptr(new operations::drop_table(name));
    m_operations.emplace(ptr);

    return builders::drop_table(ptr);
}

dodbm::builders::alter_table dodbm::builders::migration::alter_table(const std::string& name)
{
    std::shared_ptr<operations::alter_table> ptr(new operations::alter_table(name));
    m_operations.emplace(ptr);

    return builders::alter_table(ptr);
}

dodbm::builders::rename_table dodbm::builders::migration::rename_table(const std::string& name)
{
    std::shared_ptr<operations::rename_table> ptr(new operations::rename_table(name));
    m_operations.emplace(ptr);

    return builders::rename_table(ptr);
}

dodbm::builders::drop_column dodbm::builders::migration::drop_column(const std::string& name)
{
    std::shared_ptr<operations::drop_column> ptr(new operations::drop_column(name));
    m_operations.emplace(ptr);

    return builders::drop_column(ptr);
}

dodbm::builders::rename_column dodbm::builders::migration::rename_column(const std::string& name)
{
    std::shared_ptr<operations::rename_column> ptr(new operations::rename_column(name));
    m_operations.emplace(ptr);

    return builders::rename_column(ptr);
}
