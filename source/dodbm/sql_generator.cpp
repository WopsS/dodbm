#include <dodbm/sql_generator.hpp>
#include <dodbm/exception.hpp>

std::queue<dodbm::command> dodbm::sql_generator::generate(std::queue<operation> operations)
{
    std::queue<command> commands;

    while (!operations.empty())
    {
        auto& operation = operations.front();

        switch (operation.get_type())
        {
            default:
            {
                throw dodbm::exception("Unhandled operation type (" + std::to_string(static_cast<uint32_t>(operation.get_type())) + ")");
            }
        }

        operations.pop();
    }

    return commands;
}
