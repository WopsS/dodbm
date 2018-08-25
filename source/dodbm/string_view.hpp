#pragma once

#include <cassert>
#include <string>

#ifdef _MSVC_LANG
#define DODBM_CPLUSPLUS _MSVC_LANG
#else
#define DODBM_CPLUSPLUS __cplusplus
#endif

#if DODBM_CPLUSPLUS >= 201402L
#define DODBM_CPP14_OR_GREATER
#endif

#if DODBM_CPLUSPLUS >= 201703L
#define DODBM_CPP17_OR_GREATER
#endif

#ifdef DODBM_CPP17_OR_GREATER
#include <string_view>
#endif

namespace dodbm
{
#ifdef DODBM_CPP17_OR_GREATER
    using string_view = std::string_view;
#else
    template<typename CharT, typename Traits = std::char_traits<CharT>>
    class basic_string_view
    {
    public:

        static_assert(std::is_same<CharT, typename Traits::char_type>::value, "Bad char_traits for basic_string_view");

        using value_type = CharT;
        using const_pointer = const CharT*;
        using const_iterator = const_pointer;
        using size_type = std::size_t;

#ifdef DODBM_CPP17_OR_GREATER
        static constexpr auto npos{ static_cast<size_type>(-1) };
#else
        static const size_type npos = -1;
#endif

        template<std::size_t N>
        constexpr basic_string_view(const value_type (&s)[N])
            : _data(&s[0])
            , _size(N - 1)
        {
        }

        constexpr basic_string_view(const_pointer s, size_type count)
            : _data(s)
            , _size(count)
        {
        }

        constexpr basic_string_view(const basic_string_view& other) noexcept = default;

#ifdef DODBM_CPP14_OR_GREATER
        constexpr
#endif
        basic_string_view& operator=(const basic_string_view&) noexcept = default;

        constexpr const_iterator begin() const noexcept
        {
            return _data;
        }

        constexpr const_iterator end() const noexcept
        {
            return _data + _size;
        }

        constexpr size_type length() const noexcept
        {
            return _size;
        }

#ifdef DODBM_CPP14_OR_GREATER
        constexpr
#endif
        void remove_prefix(size_type n)
        {
            assert(n <= length());

            _data += n;
            _size -= n;
        }

        constexpr basic_string_view substr(size_type pos = 0, size_type count = npos) const
        {
            return { _data + pos, std::min(count, length() - pos) };
        }

#ifdef DODBM_CPP14_OR_GREATER
        constexpr
#endif
        size_type find(basic_string_view v, size_type pos = 0) const noexcept
        {
            if (v._size > _size || pos > (_size - v._size))
            {
                return npos;
            }

            if (v._size == 0) // Nothing to search.
            {
                return npos;
            }

            auto end = _data + (_size - v._size) + 1;
            for (auto i = _data + pos;; ++i)
            {
                i = Traits::find(i, static_cast<size_t>(end - i), *v._data);
                if (!i)
                {
                    return npos;
                }

                if (Traits::compare(i, v._data, v._size) == 0) // Found.
                {
                    return (static_cast<size_t>(i - _data));
                }
            }
        }

#ifdef DODBM_CPP14_OR_GREATER
        constexpr
#endif
        size_type find_last_of(basic_string_view v, size_type pos = npos) const noexcept
        {
            pos = std::min(pos, length() - 1);

            for (auto i = _data + pos; i != _data; --i)
            {
                if (Traits::find(v._data, v._size, *i))
                {
                    return (static_cast<size_t>(i - _data)); // Found a match.
                }
            }

            return npos;
        }

    private:

        const_pointer _data;
        size_type _size;
    };

    using string_view = basic_string_view<char>;
#endif
}