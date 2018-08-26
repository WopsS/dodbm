#include <dodbm/operation.hpp>

dodbm::operation::operation(type type)
    : m_type(type)
{
}

const dodbm::operation::type dodbm::operation::get_type() const
{
    return m_type;
}
