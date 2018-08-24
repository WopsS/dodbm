#include <dodbm/dodbm.hpp>
#include <dodbm/builders/alter_table.hpp>

const dodbm::builders::alter_table& dodbm::builders::alter_table::comment(const std::string& text) const
{
    m_operation->set_comment(text);
    return *this;
}
