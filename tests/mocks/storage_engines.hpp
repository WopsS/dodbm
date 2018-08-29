#pragma once

namespace mocks
{
    namespace storage_engines
    {
        struct empty
        {
            static constexpr auto name = "";
        };

        struct InnoDB
        {
            static constexpr auto name = "InnoDB";
        };
    }
}