#include <dodbm/mysql/provider.hpp>

dodbm::mysql::provider::provider(const config& config)
{
}

dodbm::mysql::provider::~provider()
{
}

void dodbm::mysql::provider::start_transaction()
{
}

void dodbm::mysql::provider::commit()
{
}

void dodbm::mysql::provider::rollback()
{
}

std::string dodbm::mysql::provider::compile(operations::alter_table* operation)
{
    return std::string();
}

std::string dodbm::mysql::provider::compile(operations::create_table* operation)
{
    return std::string();
}

std::string dodbm::mysql::provider::compile(operations::drop_table* operation)
{
    return std::string();
}

std::string dodbm::mysql::provider::compile(operations::rename_table* operation)
{
    return std::string();
}

bool dodbm::mysql::provider::execute(const std::string& sql)
{
    return false;
}