#include <dodbm/operation.hpp>

bool dodbm::operation::is_allowed_in_prepared_statements() const
{
    return true;
}
