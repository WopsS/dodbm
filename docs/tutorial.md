# Tutorial

### Content

* [Using dodbm](#using-dodbm)
* [Using a provider](#using-a-provider)
* [Writing a migration](#writing-a-migration)
* [Applying migrations](#applying-migrations)
* [Reverting a migration](#reverting-a-migration)

## Using dodbm

The simple way to use **dodbm** is to include **dodbm.hpp** in your project.

## Using a provider

After you include the main library, you need to use a provider in order to create a migration (since the core library doesn't have types for the database and each provider needs to implement them).

You can see the available providers [here](/providers), if it is missing you can try to write one using [this tutorial](writing-a-provider.md).

To use a provider (for example **MySQL**) you need to include it.

```cpp
#include <dodbm/mysql/provider.hpp>
```

## Writing a migration

A migration should extend **dodbm::migration** class and implement 2 virtual functions (**up** and **down**).

```cpp
#include <dodbm>

class M20180905145016_InitialMigration : public dodbm::migration
{
protected:

    void up(dodbm::migration_builder& builder) final
    {
        // Your code when migration is ran.

        /*
        * The following code will create "users" table with 2 columns:
        * id - INT, AUTO_INCREMENTED, PRIMARY KEY.
        * name - VARCHAR(32), NOT NULL.
        */
        builder.create_table("users")
                .columns([](dodbm::columns_builder& builder)
                {
                    builder.add<dodbm::mysql::int_t>("id")
                        .auto_incremented();

                    builder.add<dodbm::mysql::varchar>("name")
                        .max_length(32);
                })
                .constraints([](dodbm::constraints_builder& builder)
                {
                    builder.primary_key()
                        .column("id");
                });
    }

    void down(dodbm::migration_builder& builder) final
    {
        // Code when migration is rolling back.

        // The following code will drop the table "users".
        builder.drop_table("dbm");
    }
};
```
To know more about migrations read [migrations](migrations.md).

## Applying migrations

In order to apply (or rollback) a migration you need a **repository** and to add the migration to it.

```cpp
dodbm::repository repository(some_provider);
repository.add<M20180905145016_InitialMigration>();

repository.migrate();
```

You can add multiple migrations in one repository, it will run migrations that are not already applied, the old ones are ignored.

**Notes:**

* The function `repository.add<M20180905145016_InitialMigration>();` will ignore any namespace, if a migration is in one, so make sure you have a unique migration name.
* Migrations are ordered alphabetically.

## Reverting a migration

It is almost the same thing as migrating one, but instead of using `add` you need to use `rollback`.

```cpp
repository.rollback<M20180905145016_InitialMigration>();
```

You can also rollback multiple migrations until a specific one using `rollback_to` function.

```cpp
repository.add<M20180905145016_InitialMigration>();
// Other migrations.

repository.rollback_to<M20180905145016_InitialMigration>()
```

This will rollback every migration to `M20180905145016_InitialMigration`.