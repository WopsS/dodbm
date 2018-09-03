#pragma once

namespace dodbm
{
    namespace mysql
    {
        inline namespace storage_engines
        {
            struct aria
            {
                static constexpr auto name = "Aria";
            };

            struct csv
            {
                static constexpr auto name = "CSV";
            };

            struct innodb
            {
                static constexpr auto name = "InnoDB";
            };

            struct memory
            {
                static constexpr auto name = "MEMORY";
            };

            struct mrg_myisam
            {
                static constexpr auto name = "MRG_MyISAM";
            };

            struct myisam
            {
                static constexpr auto name = "MyISAM";
            };

            struct sequence
            {
                static constexpr auto name = "SEQUENCE";
            };
        }
    }
}