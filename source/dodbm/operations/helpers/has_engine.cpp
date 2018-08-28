#include <dodbm/operations/helpers/has_engine.hpp>

void dodbm::operations::helpers::has_engine::set_engine(storage_engine engine)
{
    m_engine = std::move(engine);
}

const dodbm::storage_engine& dodbm::operations::helpers::has_engine::get_engine() const
{
    return m_engine;
}
