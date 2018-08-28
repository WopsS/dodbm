#include <dodbm/operations/helpers/has_comment.hpp>

void dodbm::operations::helpers::has_comment::set_comment(const std::string& text)
{
    m_comment = text;
}

const std::string& dodbm::operations::helpers::has_comment::get_comment() const
{
    return m_comment;
}
