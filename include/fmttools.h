#ifndef _FORMATTING_H_
#define _FORMATTING_H_

#include <format>

// With this concept...
template<typename T>
concept trivially_formattable = requires(const T&x, std::format_context::iterator i)
{
    {
        format_value(x, i)
    } -> std::same_as<std::format_context::iterator>;
};

// And this partial specialization...
template<trivially_formattable T>
struct std::formatter<T> {
    constexpr auto parse(auto&ctx) { return ctx.begin(); }
    auto format(const T&thing, auto&ctx) const { return format_value(thing, ctx.out()); }
};

#endif
