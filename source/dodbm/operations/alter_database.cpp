#include <dodbm/operations/alter_database.hpp>

dodbm::operation::type dodbm::operations::alter_database::get_type() const
{
    return type::alter_database;
}
