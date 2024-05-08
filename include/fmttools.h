#ifndef _FORMATTING_H_
#define _FORMATTING_H_

#include <format>

template<typename T>
concept displayable = requires(const T&x, std::format_context::iterator i)
{
    {
        format_value(x, i)
    } -> std::same_as<std::format_context::iterator>;
};

// And this partial specialization...
template<displayable T>
struct std::formatter<T> {
    constexpr auto parse(auto&ctx) { return ctx.begin(); }
    auto format(const T&thing, auto&ctx) const { return format_value(thing, ctx.out()); }
};

#endif
