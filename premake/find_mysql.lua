local function getwindowspaths(arch)
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
        path = os.findheader("mariadb/mysql.h")

        if path == nil then
            path = os.findheader("mysql.h")
        else
            path = path .. "/mariadb"
        end
    else
        path = path .. "/mysql"
    end

    if path == nil and os.istarget("windows") then
        path = os.pathsearch("mysql.h", table.implode(getwindowspaths(arch), "", "/include", ";"))
    end

    return path
end

function findmysqllib(arch)
    local path = nil

    if os.istarget("windows") then
        path = os.pathsearch("libmariadb.lib", table.implode(getwindowspaths(arch), "", "/lib", ";"))
    else
        path = os.findlib("mariadb")

        if path == nil then
            path = os.findlib("mariadbclient")
        end
    end
    
    return path
end

function getmysqllib()
    if os.istarget("windows") then
        return "libmariadb"
    else
        if os.findlib("mariadb") then
            return "mariadb"
        end

        if os.findlib("mariadbclient") then
            return "mariadbclient"
        end
    end
    
    return ""
end