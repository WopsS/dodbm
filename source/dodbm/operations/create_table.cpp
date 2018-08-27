#include <dodbm/operations/create_table.hpp>
#include <dodbm/exception.hpp>

dodbm::operations::create_table::create_table(const std::string& name)
    : m_name(name)
{
    if (name.empty())
    {
        throw dodbm::exception("Table name is empty");
    }
}

dodbm::operation::type dodbm::operations::create_table::get_type() const
{
    return type::create_table;
}

const std::string& dodbm::operations::create_table::get_name() const
{
    return m_name;
}

void dodbm::operations::create_table::set_engine(std::unique_ptr<storage_engine> engine)
{
    m_engine = std::move(engine);
}

const dodbm::storage_engine& dodbm::operations::create_table::get_engine() const
{
    return *m_engine;
}

void dodbm::operations::create_table::set_collation(collation value)
{
    m_collation = std::move(value);
}

const dodbm::collation& dodbm::operations::create_table::get_collation() const
{
    return m_collation;
}

void dodbm::operations::create_table::set_comment(const std::string& text)
{
    m_comment = text;
}

const std::string& dodbm::operations::create_table::get_comment() const
{
    return m_comment;
}
