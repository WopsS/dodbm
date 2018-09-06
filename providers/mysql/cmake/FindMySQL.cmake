# Try to find MariaDB and MySQL library.

find_path(MYSQL_INCLUDE_DIR
            NAMES mysql.h
            PATH_SUFFIXES mariadb mysql)

find_library(MYSQL_LIBRARY
                NAMES libmariadb.lib mariadb mariadbclient mysqlclient
                PATH_SUFFIXES mariadb mysql)

find_package(PackageHandleStandardArgs REQUIRED)
find_package_handle_standard_args(MySQL DEFAULT_MSG MYSQL_INCLUDE_DIR MYSQL_LIBRARY)

mark_as_advanced(MYSQL_INCLUDE_DIR MYSQL_LIBRARY)

set(MYSQL_INCLUDE_DIR ${MYSQL_INCLUDE_DIR})
set(MYSQL_LIBRARY ${MYSQL_LIBRARY})