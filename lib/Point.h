#pragma once

#include <fmt/format.h>
#include "Tuple.h"

class Point : public Tuple
{
public:
    Point(double x, double y, double z);
};

template <>
struct fmt::formatter<Point> : fmt::formatter<std::string>
{
    template <typename FormatContext>
    auto format(Point const& p, FormatContext& ctx)
    {
        return formatter<std::string>::format(fmt::format("({}, {}, {})", p.x(), p.y(), p.z()), ctx);
    }
};
