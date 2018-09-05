#include <dodbm/mysql/connection.hpp>
#include <dodbm/mysql/exception.hpp>
#include <dodbm/mysql/statement.hpp>

dodbm::mysql::connection::connection(const config& config)
{
    m_mysql = mysql_init(nullptr);
    if (!m_mysql)
    {
        throw dodbm::mysql::exception("Could not initalize MySQL object");
    }

    my_bool reconnect = true;
    if (mysql_options(m_mysql, MYSQL_OPT_RECONNECT, &reconnect))
    {
        throw dodbm::mysql::exception("Could not set option MYSQL_OPT_RECONNECT");
    }

    if (config.has_ssl())
    {
        const auto& ssl = config.ssl;
        mysql_ssl_set(m_mysql, ssl.key.c_str(), ssl.cert.c_str(),
                      ssl.ca.empty() ? nullptr : ssl.ca.c_str(),
                      ssl.caPath.empty() ? nullptr : ssl.caPath.c_str(),
                      ssl.cipher.empty() ? nullptr : ssl.cipher.c_str());
    }

    if (!mysql_real_connect(m_mysql,
                           config.host.empty() ? nullptr : config.host.c_str(),
                           config.user.c_str(),
                           config.password.empty() ? nullptr : config.password.c_str(),
                           config.database.c_str(),
                           config.port,
                           config.unix_socket.empty() ? nullptr : config.unix_socket.c_str(),
                           config.client_flag))
    {
        throw dodbm::mysql::exception("Could not connect to the database server", mysql_error(m_mysql), mysql_errno(m_mysql));
    }

    if (mysql_autocommit(m_mysql, false))
    {
        throw dodbm::mysql::exception("Could not set autocommit to false", mysql_error(m_mysql), mysql_errno(m_mysql));
    }

    if (mysql_set_character_set(m_mysql, config.charset.c_str()))
    {
        throw dodbm::mysql::exception("Could not set charset (" + config.charset + ")", mysql_error(m_mysql), mysql_errno(m_mysql));
    }

    if (mysql_select_db(m_mysql, config.database.c_str()))
    {
        throw dodbm::mysql::exception("Could not select database \"" + config.database + "\"", mysql_error(m_mysql), mysql_errno(m_mysql));
    }

    m_schema = config.database;
}

dodbm::mysql::connection::~connection()
{
    if (m_mysql)
    {
        mysql_close(m_mysql);
        m_mysql = nullptr;
    }
}

void dodbm::mysql::connection::start_transaction()
{
    if (debug)
    {
        debug("Beginning transaction");
    }

    std::string query = "START TRANSACTION;";
    if (mysql_real_query(m_mysql, query.c_str(), query.size()))
    {
        throw dodbm::mysql::exception("Failed to start a transaction", mysql_error(m_mysql), mysql_errno(m_mysql));
    }
}

void dodbm::mysql::connection::commit()
{
    if (debug)
    {
        debug("Committing transaction");
    }

    if (mysql_commit(m_mysql))
    {
        throw dodbm::mysql::exception("Failed to commit the transaction", mysql_error(m_mysql), mysql_errno(m_mysql));
    }
}

void dodbm::mysql::connection::rollback()
{
    if (debug)
    {
        debug("Rolling back transaction");
    }

    if (mysql_rollback(m_mysql))
    {
        throw dodbm::mysql::exception("Failed to rollback the transaction", mysql_error(m_mysql), mysql_errno(m_mysql));
    }
}

void dodbm::mysql::connection::execute_non_query(const std::string& text)
{
    mysql_real_query(m_mysql, text.c_str(), text.size());
}

void dodbm::mysql::connection::execute_non_query(const std::string& text, const std::vector<db_value>& parameters)
{
    mysql::statement statement(m_mysql, text);
    statement.bind(parameters);

    if (debug)
    {
        debug("Executing \"" + text + "\" with " + std::to_string(parameters.size()) + " parameters");
    }

    statement.execute();
}

dodbm::db_result dodbm::mysql::connection::execute_query(const std::string& text, const std::vector<db_value>& parameters)
{
    mysql::statement statement(m_mysql, text);
    statement.bind(parameters);

    if (debug)
    {
        debug("Executing query \"" + text + "\" with " + std::to_string(parameters.size()) + " parameters");
    }

    return statement.query();
}

std::string dodbm::mysql::connection::get_schema_name() const
{
    return m_schema;
}
