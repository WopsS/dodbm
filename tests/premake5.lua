project("dodbm-tests")
    kind("ConsoleApp")
    language("C++")
    targetdir(buildpath("bin"))

    includedirs(
    {
        ".",
        dependenciespath("catch2", "single_include"),
        sourcepath(basepath),
        testspath(basepath)
    })

    files({  "**.cpp", "**.hpp" })
    links({ "dodbm" })