#include <dodbm/operations/add_unique_constraint.hpp>

dodbm::operation::type dodbm::operations::add_unique_constraint::get_type() const
{
    return type::add_unique_constraint;
}
