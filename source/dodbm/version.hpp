#pragma once

#include <cstdint>

namespace dodbm
{
    namespace version
    {
        constexpr const char* as_string()
        {
            return "0.1.0";
        }

        constexpr uint32_t as_int()
        {
            return 100;
        }

        constexpr uint8_t get_major()
        {
            return 0;
        }

        constexpr uint8_t get_minor()
        {
            return 1;
        }

        constexpr uint8_t get_patch()
        {
            return 0;
        }
    }
}