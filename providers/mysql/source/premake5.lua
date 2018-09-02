include("find_mysql.lua")

project("mysql-provider")
    kind("StaticLib")
    language("C++")
    
    if buildpath ~= nil then
        targetdir(buildpath("libs"))
    end

    includedirs(
    {
        ".",
        sourcepath(basepath)
    })

    if findmysqlheader ~= nil then
        filter({ "architecture:x86" })
            includedirs({ findmysqlheader("x86") })

        filter({ "architecture:x86_64" })
            includedirs({ findmysqlheader("x86_64") })
    end

    if findmysqllib ~= nil then
        filter({ "architecture:x86", "system:windows" })
            libdirs({ findmysqllib("x86") })

        filter({ "architecture:x86_64", "system:windows" })
            libdirs({ findmysqllib("x86_64") })
    end

    filter({})

    links({ "mariadbclient" })

    files({  "**.cpp", "**.hpp" })

    vpaths({ ["*"] = "dodbm/mysql/**.*" })