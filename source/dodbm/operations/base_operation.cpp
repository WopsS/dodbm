#include <dodbm/stdafx.hpp>
#include <dodbm/operations/base_operation.hpp>

dodbm::operations::base_operation::base_operation(operation_type type)
    : m_type(type)
{
}

dodbm::operations::operation_type dodbm::operations::base_operation::get_type()
{
    return m_type;
}
