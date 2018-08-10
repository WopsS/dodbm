project("tests")
    kind("ConsoleApp")
    language("C++")
    targetdir(buildpath("bin"))

    includedirs(
    {
        ".",
        dependenciespath("catch2/single_include"),
        sourcepath()
    })

    files({  "**.cpp", "**.hpp" })
    links({ "dodbm" })