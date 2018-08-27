#include <dodbm/builders/migration.hpp>

std::queue<std::shared_ptr<dodbm::operation>> dodbm::builders::migration::get_operations() const
{
    return m_operations;
}
