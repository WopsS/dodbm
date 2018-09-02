local function getpaths(arch)
    local paths = {}
    if arch == "x86_64" then
        table.insert(paths, "C:/Program Files/MariaDB/MariaDB Connector C 64-bit")
    else
        table.insert(paths, "C:/Program Files (x86)/MariaDB/MariaDB Connector C")
    end

    return paths
end

function findmysqlheader(arch)
    local path = os.findheader("mysql/mysql.h")
    if path == nil then
        path = os.findheader("mysql.h")
    else
        path = path .. "/mysql"
    end

    if path == nil and os.istarget("windows") then
        path = os.pathsearch("mysql.h", table.implode(getpaths(arch), "", "/include", ";"))
    end

    return path
end

function findmysqllib(arch)
    local path = nil

    if os.istarget("windows") then
        path = os.pathsearch("mariadbclient.lib", table.implode(getpaths(arch), "", "/lib", ";"))
    else
        path = os.pathsearch("mariadbclient")
    end
    
    return path
end