#include "Tuple.h"

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
    return isEqual(_x, rhs._x) &&
           isEqual(_y, rhs._y) &&
           isEqual(_z, rhs._z) &&
           isEqual(_w, rhs._w);
}

std::ostream& operator<<(std::ostream& os, const Tuple& tuple)
{
    os << "(" << tuple._x << ", " << tuple._y << ", " << tuple._z << ", " << tuple._w << ")";
    return os;
}

bool isEqual(double a, double b)
{
    return std::abs(a - b) < EPSILON;
}
