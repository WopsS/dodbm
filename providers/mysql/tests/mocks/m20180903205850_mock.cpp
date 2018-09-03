#include <mocks/m20180903205850_mock.hpp>

#include <dodbm/mysql/types.hpp>

void mocks::m20180903205850_mock::up(dodbm::migration_builder& builder)
{
    builder.create_table("do")
        .columns([](dodbm::columns_builder& builder)
        {
            builder.add<dodbm::mysql::int_t>("id")
                .auto_incremented();

            builder.add<dodbm::mysql::boolean>("some_boolean");
        })
        .constraints([](dodbm::constraints_builder& builder)
        {
            builder.primary_key()
                .column("id");
        });

    builder.create_table("dbm")
        .columns([](dodbm::columns_builder& builder)
        {
            builder.add<dodbm::mysql::int_t>("id")
                .auto_incremented();

            builder.add<dodbm::mysql::int_t>("do_id");
            builder.add<dodbm::mysql::varchar>("text")
                .default_value("some cool text")
                .max_length(128);
        })
        .constraints([](dodbm::constraints_builder& builder)
        {
            builder.primary_key()
                .column("id");

            builder.foreign_key()
                .column("do_id")
                .from_table("do")
                .on_column("id");
        });

    builder.insert_data({ { "some_boolean", false } })
        .in("do");

    builder.update_data({ { "some_boolean", false } })
        .set({ { "some_boolean", true } })
        .table("do");
}

void mocks::m20180903205850_mock::down(dodbm::migration_builder& builder)
{
    builder.delete_data({ { "some_boolean", true } })
        .from("do");

    builder.drop_table("dbm");
    builder.drop_table("do");
}
