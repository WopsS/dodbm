#pragma once

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

        constexpr uint8_t major()
        {
            return 0;
        }

        constexpr uint8_t minor()
        {
            return 1;
        }

        constexpr uint8_t patch()
        {
            return 0;
        }
    }
}