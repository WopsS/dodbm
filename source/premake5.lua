project("dodbm")
    kind("StaticLib")
    language("C++")
    pchheader("dodbm/dodbm.hpp")
    pchsource("dodbm/dodbm.cpp")

    if buildpath ~= nil then
        targetdir(buildpath("libs"))
    end
    
    includedirs({ "." })   

    files({  "**.cpp", "**.hpp" })