#include <dodbm/operations/drop_foreign_key.hpp>

dodbm::operation::type dodbm::operations::drop_foreign_key::get_type() const
{
    return type::drop_foreign_key;
}
