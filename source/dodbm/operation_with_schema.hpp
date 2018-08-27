#pragma once

#include <string>

#include <dodbm/operation.hpp>

namespace dodbm
{
    class operation_with_schema : public operation
    {
    public:

        operation_with_schema() = default;
        ~operation_with_schema() = default;

        void set_schema(const std::string& name);
        const std::string& get_schema() const;

    private:

        std::string m_schema;
    };
}