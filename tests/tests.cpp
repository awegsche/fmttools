#include <gtest/gtest.h>
#include <string>
#include <format>

#include "fmttools.h"

struct Point {
    int x;
    int y;
    int z;
};

auto format_value(const Point& point, auto fmt_iter) {
    return std::format_to(fmt_iter, "({}, {}, {})", point.x, point.y, point.z);
}

TEST(Simple, Struct) {
    const std::string point_str = "(1, 2, 3)";
    const Point point = { 1, 2, 3 };

    EXPECT_EQ(point_str, std::format("{}", point));
}

