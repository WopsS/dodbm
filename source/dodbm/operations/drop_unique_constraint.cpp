#include <dodbm/operations/drop_unique_constraint.hpp>

dodbm::operation::type dodbm::operations::drop_unique_constraint::get_type() const
{
    return type::drop_unique_constraint;
}
