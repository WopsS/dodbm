include("find_mysql.lua")

project("mysql-provider-tests")
    kind("ConsoleApp")
    language("C++")
    targetdir(buildpath("bin"))

    includedirs(
    {
        ".",
        dependenciespath("catch2", "single_include"),
        sourcepath(basepath),
        sourcepath(providerspath("mysql")),
        testspath(providerspath("mysql"))
    })

    filter({ "architecture:x86" })
        includedirs({ findmysqlheader("x86") })

    filter({ "architecture:x86_64" })
        includedirs({ findmysqlheader("x86_64") })

    filter({ "architecture:x86", "system:windows" })
        libdirs({ findmysqllib("x86") })

    filter({ "architecture:x86_64", "system:windows" })
        libdirs({ findmysqllib("x86_64") })

    filter({})

    links({ getmysqllib() })

    files({  "**.cpp", "**.hpp" })
    links({ "dodbm", "mysql-provider" })

    vpaths({ ["*"] = "**.*" })