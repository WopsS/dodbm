#include <dodbm/mysql/statement.hpp>

#include <dodbm/mysql/exception.hpp>
#include <dodbm/mysql/result_metadata.hpp>

dodbm::mysql::statement::statement(MYSQL* mysql, const std::string& query)
    : m_mysql(mysql)
{
    m_stmt = mysql_stmt_init(mysql);
    if (!m_stmt)
    {
        throw dodbm::mysql::exception("Could not initalize MySQL statement object");
    }

    if (mysql_stmt_prepare(m_stmt, query.c_str(), query.size()))
    {
        throw dodbm::mysql::exception("Could not prepare statement \"" + query + "\"", mysql_error(mysql), 0, mysql_stmt_error(m_stmt), mysql_stmt_errno(m_stmt));
    }
}

dodbm::mysql::statement::~statement()
{
    if (m_stmt)
    {
        mysql_stmt_free_result(m_stmt);
        mysql_stmt_close(m_stmt);

        m_stmt = nullptr;
    }
}

void dodbm::mysql::statement::bind(const std::vector<db_value>& parameters)
{
    auto param_count = mysql_stmt_param_count(m_stmt);

    if (parameters.size() != param_count)
    {
        throw dodbm::mysql::exception("Size of parameters passed is different from prepared ones");
    }

    if (param_count > 0)
    {
        // Store a list of raw binds to be used for "mysql_stmt_bind_param".
        std::vector<MYSQL_BIND*> raw_binds;

        m_binds.reserve(param_count);
        raw_binds.reserve(param_count);

        if (m_binds.capacity() > 0)
        {
            for (auto& parameter : parameters)
            {
                std::unique_ptr<mysql::bind> bind(new mysql::bind(std::move(parameter)));

                raw_binds.emplace_back(bind->get_raw());
                m_binds.emplace_back(std::move(bind));
            }
        }

        if (raw_binds.size() > 0)
        {
            if (mysql_stmt_bind_param(m_stmt, raw_binds.front()))
            {
                throw dodbm::mysql::exception("Could not bind the parameters", mysql_error(m_mysql), mysql_errno(m_mysql), mysql_stmt_error(m_stmt), mysql_stmt_errno(m_stmt));
            }
        }
    }
}

std::size_t dodbm::mysql::statement::execute()
{
    if (mysql_stmt_execute(m_stmt))
    {
        throw dodbm::mysql::exception("Could not execute the statement", mysql_error(m_mysql), mysql_errno(m_mysql), mysql_stmt_error(m_stmt), mysql_stmt_errno(m_stmt));
    }

    return mysql_stmt_affected_rows(m_stmt);
}

dodbm::db_result dodbm::mysql::statement::query()
{
    if (mysql_stmt_execute(m_stmt))
    {
        throw dodbm::mysql::exception("Could not execute the statement", mysql_error(m_mysql), mysql_errno(m_mysql), mysql_stmt_error(m_stmt), mysql_stmt_errno(m_stmt));
    }

    // Clean up the param binds, we will use it for result too.
    m_binds.clear();

    // Set "STMT_ATTR_UPDATE_MAX_LENGTH" because we want the full length and we don't want truncations.
    my_bool max_length = true;
    mysql_stmt_attr_set(m_stmt, STMT_ATTR_UPDATE_MAX_LENGTH, &max_length);

    if (mysql_stmt_store_result(m_stmt))
    {
        throw dodbm::mysql::exception("Could not store the result for statement", mysql_error(m_mysql), mysql_errno(m_mysql), mysql_stmt_error(m_stmt), mysql_stmt_errno(m_stmt));
    }

    std::vector<dodbm::db_result::row> rows;

    auto field_count = mysql_stmt_field_count(m_stmt);
    if (field_count > 0)
    {
        std::vector<MYSQL_BIND*> raw_binds;

        result_metadata result(m_stmt);
        auto fields = mysql_fetch_fields(result.get());

        for (size_t i = 0; i < field_count; i++)
        {
            const auto& field = fields[i];

            std::unique_ptr<mysql::bind> bind(new mysql::bind(field));

            raw_binds.emplace_back(bind->get_raw());
            m_binds.emplace_back(std::move(bind));
        }

        if (mysql_stmt_bind_result(m_stmt, raw_binds.front()))
        {
            throw dodbm::mysql::exception("Could not bind the result", mysql_error(m_mysql), mysql_errno(m_mysql), mysql_stmt_error(m_stmt), mysql_stmt_errno(m_stmt));
        }

        rows.reserve(mysql_stmt_num_rows(m_stmt));

        while (!mysql_stmt_fetch(m_stmt))
        {
            std::unordered_map<std::string, db_value> row_fields;

            for (size_t i = 0; i < field_count; i++)
            {
                const auto& field = fields[i];
                auto value = m_binds[i]->get_value();

                row_fields.emplace(field.name, std::move(value));
            }

            rows.emplace_back(std::move(row_fields));
        }
    }

    return db_result(rows);
}
