#include <dodbm/builders/constraints.hpp>

dodbm::builders::add_foreign_key dodbm::builders::constraints::foreign_key(const std::string& name)
{
    std::shared_ptr<operations::add_foreign_key> ptr(new operations::add_foreign_key(name));
    foreign_keys.emplace_back(ptr);

    return builders::add_foreign_key(ptr);
}

dodbm::builders::add_primary_key dodbm::builders::constraints::primary_key(const std::string& name)
{
    primary_key_ = std::shared_ptr<operations::add_primary_key>(new operations::add_primary_key(name));
    return builders::add_primary_key(primary_key_);
}

dodbm::builders::add_unique_constraint dodbm::builders::constraints::unique_constraint(const std::string& name)
{
    std::shared_ptr<operations::add_unique_constraint> ptr(new operations::add_unique_constraint(name));
    unique_constraints.emplace_back(ptr);

    return builders::add_unique_constraint(ptr);
}
