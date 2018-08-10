require("premake", ">=5.0.0-alpha12")
include("version.lua")

basepath = path.getdirectory(os.getcwd());
buildpath = function(p)  p = p or "lib"; return path.join(basepath, "build", "%{cfg.buildcfg:lower()}", p).."/" end
sourcepath = function(p) return path.join(basepath, "source", p) end
dependenciespath = function(p) return path.join(basepath, "dependencies", p).."/" end
testspath = function(p) return path.join(basepath, "tests", p).."/" end

Version:format(sourcepath("dodbm/version.hpp.in"))

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

    include(sourcepath())
    include(testspath())