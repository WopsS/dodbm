#include <dodbm/operations/helpers/column.hpp>

dodbm::operations::helpers::column::column(const std::string& name)
    : has_required_name(name)
    , m_max_length(0)
    , m_decimals(0)
    , m_attribute(attribute::none)
    , m_is_nullable(false)
    , m_is_auto_incremented(false)
    , m_move_first(false)
{
}

void dodbm::operations::helpers::column::set_column_type(const std::string& type)
{
    m_column_type = type;
}

const std::string& dodbm::operations::helpers::column::get_column_type() const
{
    return m_column_type;
}

void dodbm::operations::helpers::column::set_max_length(uint64_t max_length)
{
    m_max_length = max_length;
}

uint64_t dodbm::operations::helpers::column::get_max_length() const
{
    return m_max_length;
}

void dodbm::operations::helpers::column::set_decimals(uint8_t decimals)
{
    m_decimals = decimals;
}

uint8_t dodbm::operations::helpers::column::get_decimals() const
{
    return m_decimals;
}

void dodbm::operations::helpers::column::set_values(std::vector<std::string> values)
{
    m_values = std::move(values);
}

const std::vector<std::string>& dodbm::operations::helpers::column::get_values() const
{
    return m_values;
}

void dodbm::operations::helpers::column::set_default_value(default_value value)
{
    if (value == default_value::current_timestamp)
    {
        set_default_value("CURRENT_TIMESTAMP");
    }
    else if (value == default_value::null)
    {
        set_default_value("NULL");
    }
}

void dodbm::operations::helpers::column::set_default_value(db_value value)
{
    m_default_value = std::move(value);
}

const dodbm::db_value& dodbm::operations::helpers::column::get_default_value() const
{
    return m_default_value;
}

void dodbm::operations::helpers::column::set_attribute(attribute attribute)
{
    m_attribute = attribute;
}

dodbm::operations::helpers::column::attribute dodbm::operations::helpers::column::get_attribute() const
{
    return m_attribute;
}

void dodbm::operations::helpers::column::set_nullable(bool nullable)
{
    m_is_nullable = nullable;
}

bool dodbm::operations::helpers::column::is_nullable() const
{
    return m_is_nullable;
}

void dodbm::operations::helpers::column::set_auto_incremented(bool auto_incremented)
{
    m_is_auto_incremented = auto_incremented;
}

bool dodbm::operations::helpers::column::is_auto_incremented() const
{
    return m_is_auto_incremented;
}

void dodbm::operations::helpers::column::set_move_first()
{
    m_move_first = true;
}

bool dodbm::operations::helpers::column::get_move_first() const
{
    return m_move_first;
}

void dodbm::operations::helpers::column::set_move_after(const std::string& column_name)
{
    m_move_after = column_name;
}

const std::string& dodbm::operations::helpers::column::get_move_after() const
{
    return m_move_after;
}
