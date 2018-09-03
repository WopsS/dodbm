#include <dodbm/mysql/exception.hpp>

dodbm::mysql::exception::exception(const std::string& message)
    : dodbm::exception(message)
{
}

dodbm::mysql::exception::exception(const std::string& message, const std::string& error)
    : dodbm::exception(message + "; error: " + error)
{
}

dodbm::mysql::exception::exception(const std::string& message, const std::string& error, int32_t error_code)
    : dodbm::exception(message + "; error: " + error + "; code: " + std::to_string(error_code))
{
}

dodbm::mysql::exception::exception(const std::string& message, const std::string& error, int32_t error_code, const std::string& stmt_error, uint32_t stmt_error_code)
    : dodbm::exception(message + "; error: " + error + "; code: " + std::to_string(error_code) + "; stmt_error: " + stmt_error + "; stmt_error_code: " + std::to_string(stmt_error_code))
{
}
