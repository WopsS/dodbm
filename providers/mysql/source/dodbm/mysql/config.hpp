#pragma once

#include <string>

namespace dodbm
{
    namespace mysql
    {
        struct ssl_config
        {
            std::string key;
            std::string cert;
            std::string ca;
            std::string caPath;
            std::string cipher;
        };

        struct config
        {
            std::string host;
            std::string user;
            std::string password;
            std::string database;
            unsigned int port = 0;
            std::string unix_socket;
            unsigned long client_flag = 0;
            ssl_config ssl;
            std::string charset = "utf8";

            bool has_ssl()
            {
                return !ssl.key.empty() && !ssl.cert.empty();
            }
        };
    }
}