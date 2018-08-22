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

    files({  "**.cpp", "**.hpp" })