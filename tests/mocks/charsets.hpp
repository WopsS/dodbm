#pragma once

namespace mocks
{
    namespace charsets
    {
        struct empty
        {
            static constexpr auto charset = "";
        };

        struct utf8mb4
        {
            static constexpr auto charset = "utf8mb4";
        };
    }
}