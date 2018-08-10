project("dodbm")
    kind("StaticLib")
    language("C++")
    pchheader("dodbm/dodbm.hpp")
    pchsource("dodbm/dodbm.cpp")

    if buildpath ~= nil then
        targetdir(buildpath())
    end

    filter({})
    
    includedirs({ "." })   

    files({  "**.cpp", "**.hpp" })