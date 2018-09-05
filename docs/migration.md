# Migration

### Content

* [Naming](#naming)
* [Applying](#applying)
* [Reverting](#reverting)

Every migration must extend `dodbm::migration` class in order to be added to a repository.

## Naming

A migration should have a unique name and should be ordered alphabetical (internally dodbm order them alphabetically), like `MyyyyMMddhhmmss_name`, for example `M20180905160414_InitialMigration`.

## Applying

Apply a migration is done by `up` method.

```cpp
void up(dodbm::migration_builder& builder) final
{
    builder.create_table("table_name")
        .columns([](dodbm::columns_builder& builder)
        {
            builder.add<type_int>("id")
                .auto_incremented();

            builder.add<varchar>("text")
                .default_value("some text")
                .max_length(128);
        })
        .constraints([](dodbm::constraints_builder& builder)
        {
            builder.primary_key()
                .column("id");
        });
}
```

## Reverting

Reverting a migration is done by `down` method.

```cpp
void down(dodbm::migration_builder& builder) final
{
    builder.drop_table("table_name");
}
```

## Example

```cpp
class M20180905160414_InitialMigration : dodbm::migration
{
protected:

    void up(dodbm::migration_builder& builder) final
    {
        builder.create_table("table_name")
            .columns([](dodbm::columns_builder& builder)
            {
                builder.add<type_int>("id")
                    .auto_incremented();

                builder.add<varchar>("text")
                    .default_value("some text")
                    .max_length(128);
            })
            .constraints([](dodbm::constraints_builder& builder)
            {
                builder.primary_key()
                    .column("id");
            });
    }

    void down(dodbm::migration_builder& builder) final
    {
        builder.drop_table("table_name");
    }
}
```