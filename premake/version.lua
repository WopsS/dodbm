Version = {}

Version.Major = 0
Version.Minor = 1
Version.Patch = 0

function Version:format(...)
    local inputFile = path.join(...)
    local inFile = io.open(inputFile, "r")

    if not inFile then
        return nil
    end

    local outputFile = string.sub(inputFile, 0, string.len(inputFile) - 3)
    local version = Version.Major .. "." .. Version.Minor .. "." .. Version.Patch
    local readOutFile = io.open(outputFile, "r")
    local outFileContent = ""

    if readOutFile then
        outFileContent = readOutFile:read("*a")
        readOutFile:close()
    end
    
    if not string.find(outFileContent, version) then
        local outFile = io.open(outputFile, "w")
        local result = inFile:read("*a")

        result = result:gsub("%%as_string%%", "\"" .. version .. "\"")
        result = result:gsub("%%as_int%%", Version.Major * 10000 + Version.Minor * 100 + Version.Patch)
        result = result:gsub("%%major%%", Version.Major)
        result = result:gsub("%%minor%%", Version.Minor)
        result = result:gsub("%%patch%%", Version.Patch)

        outFile:write(result)
        outFile:close()
    end

    inFile:close()
end