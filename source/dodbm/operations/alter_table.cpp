#include <dodbm/operations/alter_table.hpp>
#include <dodbm/exception.hpp>

dodbm::operations::alter_table::alter_table(const std::string& name)
    : m_name(name)
{
    if (name.empty())
    {
        throw dodbm::exception("Operation \"alter_table\" requires a valid name");
    }
}

dodbm::operation::type dodbm::operations::alter_table::get_type() const
{
    return type::alter_table;
}

const std::string& dodbm::operations::alter_table::get_name() const
{
    return m_name;
}

void dodbm::operations::alter_table::set_engine(storage_engine engine)
{
    m_engine = std::move(engine);
}

const dodbm::storage_engine& dodbm::operations::alter_table::get_engine() const
{
    return m_engine;
}

void dodbm::operations::alter_table::set_collation(collation value)
{
    m_collation = std::move(value);
}

const dodbm::collation& dodbm::operations::alter_table::get_collation() const
{
    return m_collation;
}

void dodbm::operations::alter_table::set_comment(const std::string& text)
{
    if (text.empty())
    {
        throw dodbm::exception("Operation \"alter_database\" requires a valid comment");
    }

    m_comment = text;
}

const std::string& dodbm::operations::alter_table::get_comment() const
{
    return m_comment;
}
