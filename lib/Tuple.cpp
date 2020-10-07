#include "Tuple.h"

#include "Math.h"

Tuple::Tuple(double x, double y, double z, double w)
    : _x(x), _y(y), _z(z), _w(w)
{
}

double Tuple::x() const
{
    return _x;
}

double Tuple::y() const
{
    return _y;
}

double Tuple::z() const
{
    return _z;
}

double Tuple::w() const
{
    return _w;
}

bool Tuple::isPoint() const
{
    return _w == 1.0;
}

bool Tuple::isVector() const
{
    return _w == 0.0;
}

bool Tuple::operator==(const Tuple& rhs) const
{
    return isApproxEqual(_x, rhs._x) &&
           isApproxEqual(_y, rhs._y) &&
           isApproxEqual(_z, rhs._z) &&
           isApproxEqual(_w, rhs._w);
}

Tuple Tuple::operator-() const
{
    return Tuple(-_x, -_y, -_z, -_w);
}

Tuple Tuple::operator+(const Tuple& rhs) const
{
    return Tuple(_x + rhs._x,
                 _y + rhs._y,
                 _z + rhs._z,
                 _w + rhs._w);
}

Tuple Tuple::operator-(const Tuple& rhs) const
{
    return Tuple(_x - rhs._x,
                 _y - rhs._y,
                 _z - rhs._z,
                 _w - rhs._w);
}

Tuple Tuple::operator*(double rhs) const
{
    return Tuple(_x * rhs,
                 _y * rhs,
                 _z * rhs,
                 _w * rhs);
}

Tuple Tuple::operator/(double rhs) const
{
    return Tuple(_x / rhs,
                 _y / rhs,
                 _z / rhs,
                 _w / rhs);
}
