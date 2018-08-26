#pragma once

#include <cstdint>

namespace dodbm
{
    class operation
    {
    public:

        enum class type : uint8_t
        {
        };

        operation(type type);
        virtual ~operation() = default;

        const type get_type() const;

    private:

        type m_type;
    };
}