#pragma once

#include <dodbm/string_view.hpp>

namespace dodbm
{
    template<typename T>
    std::string name_of()
    {
#if defined(_MSC_VER)
        dodbm::string_view name(__FUNCSIG__);
#elif defined(__clang__) || defined(__GNUC__)
        dodbm::string_view name(__PRETTY_FUNCTION__);
#else
#error "Unsupported compiler"
#endif

#if defined(_MSC_VER)
        constexpr dodbm::string_view prefix("dodbm::name_of<class ");
        constexpr dodbm::string_view suffix(">(void)");
#elif defined(__clang__)
        constexpr dodbm::string_view prefix("dodbm::name_of() [T = ");
        constexpr dodbm::string_view suffix("]");
#elif defined(__GNUC__)
        constexpr dodbm::string_view prefix("dodbm::name_of() [with T = ");
        constexpr dodbm::string_view suffix("; ");
#else
#error "Unsupported compiler"
#endif

        name.remove_prefix(name.find(prefix) + prefix.length());
        name = name.substr(0, name.find(suffix));

        auto pos = name.find_last_of("::");
        if (pos != dodbm::string_view::npos)
        {
            name = name.substr(pos + 1);
        }

        return { name.begin(), name.end() };
    }
}