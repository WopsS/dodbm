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

    files({  "**.cpp", "**.hpp" })
    links({ "dodbm", "mysql-provider" })

    vpaths({ ["*"] = "**.*" })