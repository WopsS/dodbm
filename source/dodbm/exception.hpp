#pragma once

#include <stdexcept>

namespace dodbm
{
    class exception : public std::runtime_error
    {
        using runtime_error::runtime_error;
    };
}