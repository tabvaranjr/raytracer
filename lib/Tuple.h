#pragma once

#include <fmt/format.h>

class Tuple
{
public:
    Tuple();
    Tuple(double x, double y, double z, double w);

    double x() const;
    double y() const;
    double z() const;
    double w() const;

    bool isPoint() const;
    bool isVector() const;

    bool operator==(const Tuple& rhs) const;

    Tuple operator-() const;

    Tuple operator+(const Tuple& rhs) const;
    Tuple operator-(const Tuple& rhs) const;
    Tuple operator*(double rhs) const;
    Tuple operator/(double rhs) const;

protected:
    double _x;
    double _y;
    double _z;
    double _w;
};

template <>
struct fmt::formatter<Tuple> : fmt::formatter<std::string>
{
    template <typename FormatContext>
    auto format(Tuple const& t, FormatContext& ctx)
    {
        return formatter<std::string>::format(fmt::format("({}, {}, {}, {})", t.x(), t.y(), t.z(), t.w()), ctx);
    }
};
