#include <dodbm/builders/migration.hpp>

std::queue<dodbm::operation> dodbm::builders::migration::get_operations() const
{
    return m_operations;
}
