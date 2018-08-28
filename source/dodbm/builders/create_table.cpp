#include <dodbm/builders/create_table.hpp>

const dodbm::builders::create_table& dodbm::builders::create_table::columns(std::function<void()> func)
{
    func();
    return *this;
}

const dodbm::builders::create_table& dodbm::builders::create_table::constraints(std::function<void()> func) const
{
    func();
    return *this;
}
