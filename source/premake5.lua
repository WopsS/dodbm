project("dodbm")
    kind("StaticLib")
    language("C++")

    if buildpath ~= nil then
        targetdir(buildpath("libs"))
    end
    
    includedirs({ "." })   

    files({  "**.cpp", "**.hpp" })

    vpaths({ ["*"] = "dodbm/**.*" })