# {fmt}-tools

Some helper functions for {fmt} / std::format.

## Usage

Provides a concept `trivially_formattable` that alows writing custom formatting easily,
similar to Rust's `Display` and `Debug` traits.

```cpp
#include <fmttools.h>

struct Point {
    int x;
    int y;
    int y;
};

auto format_value(Point const& point, auto fmt_iter) {
    return std::format_value(fmt_iter, "({}, {}, {})", point.x, point.y, point.z);
}
```

