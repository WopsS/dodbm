project("dodbm")
    kind("StaticLib")
    language("C++")
    pchheader("dodbm/stdafx.hpp")
    pchsource("dodbm/stdafx.cpp")

    if buildpath ~= nil then
        targetdir(buildpath("libs"))
    end
    
    includedirs({ "." })   

    files({  "**.cpp", "**.hpp" })

    vpaths({ ["*"] = "dodbm/**.*" })