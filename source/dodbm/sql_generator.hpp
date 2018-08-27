#pragma once

#include <queue>

#include <dodbm/command.hpp>
#include <dodbm/operation.hpp>
#include <dodbm/sql_generator_helper.hpp>

namespace dodbm
{
    class sql_generator
    {
    public:

        sql_generator() = default;
        virtual ~sql_generator() = default;

        std::queue<command> generate(std::queue<operation> operations);

    protected:

        // TODO: "generate" functions for operations.
    };
}