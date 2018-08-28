#include <dodbm/operations/helpers/has_collation.hpp>

void dodbm::operations::helpers::has_collation::set_collation(collation value)
{
    m_collation = std::move(value);
}

const dodbm::collation& dodbm::operations::helpers::has_collation::get_collation() const
{
    return m_collation;
}
