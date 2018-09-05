# Writing a provider

### Content

* [What is a provider](#what-is-a-provider)
* [Implementing](#implementing)

## What is a provider

A provider is a plug-in library that let **dodbm** run operations on a specific database.

## Implementing

Before you start writing a provider, you need to create a `connection` class, which implements the following functions:

* `void start_transaction()`
* `void commit()`
* `void rollback()`
* `void execute_non_query(const std::string& text, const std::vector<dodbm::db_value>& parameters)`
* `dodbm::db_result execute_query(const std::string& text, const std::vector<dodbm::db_value>& parameters)`
* `std::string get_schema_name()`

`parameters` are the values for prepared statements.

Now you want to implement a provider, so you need to create a class that extent `dodbm::provider`.

```cpp
#include <dodbm/provider>

class my_provider : public dodbm::provider
{
public:

    my_provider() = default;
    ~my_provider() = default;
};
```

Now you need to implement a virtual function `get_connection` that returns a pointer to your connection object.

```
class my_provider : public dodbm::provider
{
public:

    my_provider() = default;
    ~my_provider() = default;

    dodbm::connection* get_connection() const final
    {
        return m_connection.get();
    }

private:

    std::unique_ptr<my_connection> m_connection
};
```

You can also override the following functions (if you want a custom behavior for them):

* `get_history_repository`
* `get_sql_generator`
* `get_sql_generator_helper`

By default these functions works with `MySQL`, you can check what you can override in them by look at the header files ([history_repository](/source/dodbm/history_repository.hpp), [history_sql_generator](/source/dodbm/sql_generator.hpp), [sql_generator_helper](/source/dodbm/sql_generator_helper.hpp)).