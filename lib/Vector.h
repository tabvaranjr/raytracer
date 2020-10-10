#pragma once

#include <fmt/format.h>
#include "Tuple.h"

class Vector : public Tuple
{
public:
    Vector(double x, double y, double z);
    Vector(const Tuple& t);

    double magnitude() const;

    Vector normalize() const;

    double dot(const Vector& rhs) const;

    Vector cross(const Vector& rhs) const;
};

template <>
struct fmt::formatter<Vector> : fmt::formatter<std::string>
{
    template <typename FormatContext>
    auto format(Vector const& v, FormatContext& ctx)
    {
        return formatter<std::string>::format(fmt::format("({}, {}, {})", v.x(), v.y(), v.z()), ctx);
    }
};

