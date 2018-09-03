#pragma once

#include <cstdint>
#include <string>

#include <dodbm/exception.hpp>

namespace dodbm
{
    namespace mysql
    {
        class exception : public dodbm::exception
        {
        public:

            exception() = default;
            exception(const std::string& message);
            exception(const std::string& message, const std::string& error);
            exception(const std::string& message, const std::string& error, int32_t error_code);
            exception(const std::string& message, const std::string& error, int32_t error_code, const std::string& stmt_error, uint32_t stmt_error_code);

            ~exception() = default;
        };
    }
}