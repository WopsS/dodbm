#include <dodbm/builders/migration.hpp>
#include <dodbm/exception.hpp>

#include <dodbm/operations/drop_table.hpp>

std::queue<std::shared_ptr<dodbm::operation>> dodbm::builders::migration::get_operations() const
{
    return m_operations;
}

dodbm::builders::create_table dodbm::builders::migration::create_table(const std::string& name)
{
    std::shared_ptr<operations::create_table> ptr(new operations::create_table(name));
    m_operations.emplace(ptr);
    
    return builders::create_table(ptr);
}

void dodbm::builders::migration::drop_table(const std::string& name)
{
    m_operations.emplace(new operations::drop_table(name));
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
