require("premake", ">=5.0.0-alpha12")
include("version.lua")

basepath = path.getdirectory(os.getcwd());
buildpath = function(...) return path.join(basepath, "build", "%{cfg.buildcfg:lower()}", ...) end
dependenciespath = function(...) return path.join(basepath, "dependencies", ...) end
providerspath = function(...) return path.join(basepath, "providers", ...) end

sourcepath = function(p) return path.join(p, "source") end
testspath = function(p) return path.join(p, "tests") end

Version:format(sourcepath(basepath), "dodbm", "version.hpp.in")

workspace("dodbm")
    architecture("x86_64")
    characterset("Unicode")
    configurations({ "Debug", "Release" })
    cppdialect("C++11")
    defines({ "_CRT_SECURE_NO_WARNINGS" })
    location("projects")
    startproject("dodbm")

    filter({ "action:vs*" })
        systemversion("10.0.17134.0")

    filter({ "configurations:Debug" })
        symbols("On")

    filter({ "configurations:Release" })
        optimize("On")
        symbols("Off")

    filter({})

    group("tests")
        include(testspath(basepath))

    group("")
        include(sourcepath(basepath))