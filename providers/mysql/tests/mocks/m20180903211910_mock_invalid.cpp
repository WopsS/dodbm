#include <mocks/m20180903211910_mock_invalid.hpp>

#include <dodbm/mysql/types.hpp>

void mocks::m20180903211910_mock_invalid::up(dodbm::migration_builder& builder)
{
    builder.add_column<dodbm::mysql::float_t>("invalid_column")
        .table("dbm")
        .auto_incremented();
}

void mocks::m20180903211910_mock_invalid::down(dodbm::migration_builder& builder)
{
    builder.drop_column("invalid_column")
        .table("dbm");
}
