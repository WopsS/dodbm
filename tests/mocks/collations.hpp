#pragma once

#include <mocks/charsets.hpp>

namespace mocks
{
    namespace collations
    {
        struct empty : charsets::empty
        {
            static constexpr auto name = "";
        };

        struct empty_name : charsets::utf8mb4
        {
            static constexpr auto name = "";
        };

        struct empty_charset : charsets::empty
        {
            static constexpr auto name = "empty_charset";
        };

        struct utf8mb4_unicode_ci : charsets::utf8mb4
        {
            static constexpr auto name = "utf8mb4_unicode_ci";
        };
    }
}