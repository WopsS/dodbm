#include <dodbm/stdafx.hpp>
#include <dodbm/repository.hpp>

dodbm::repository::repository(std::shared_ptr<base_provider> provider)
    : m_provider(provider)
{
}

void dodbm::repository::run()
{
    for (auto& i : m_migrations)
    {
        auto migration = i.second.get();

        migration_builder builder;
        migration->build(builder);

        m_provider->start_transaction();

        auto& operations = builder.operations;

        std::string sql;
        bool success = false;

        while (!operations.empty())
        {
            auto operation = operations.front().get();

            switch (operation->get_type())
            {
                case operations::operation_type::alter_table:
                {
                    sql = m_provider->compile(static_cast<operations::alter_table*>(operation));
                    break;
                }
                case operations::operation_type::create_table:
                {
                    sql = m_provider->compile(static_cast<operations::create_table*>(operation));
                    break;
                }
                case operations::operation_type::drop_table:
                {
                    sql = m_provider->compile(static_cast<operations::drop_table*>(operation));
                    break;
                }
                case operations::operation_type::rename_table:
                {
                    sql = m_provider->compile(static_cast<operations::rename_table*>(operation));
                    break;
                }
                default:
                {
                    throw dodbm::exception("Unhandled operation type (" + std::to_string(static_cast<uint32_t>(operation->get_type())) + ")");
                }
            }

            success = m_provider->execute(sql);
            if (!success)
            {
                break;
            }

            operations.pop();
        }

        // TODO: Insert migration in history table.
        if (success)
        {
            m_provider->commit();
        }
        else
        {
            m_provider->rollback();
            break;
        }
    }
}
