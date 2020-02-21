#include "Color.h"

Color::Color(double r, double g, double b)
    : Tuple(r, g, b, 0.0)
{
}

double Color::red()
{
    return _x;
}

double Color::green()
{
    return _y;
}

double Color::blue()
{
    return _z;
}

Color Color::hadamard(const Color& rhs) const
{
    return Color(_x * rhs._x,
                 _y * rhs._y,
                 _z * rhs._z);
}
