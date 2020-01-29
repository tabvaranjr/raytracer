#include "Vector.h"

#include <cmath>

Vector::Vector(double x, double y, double z)
    : Tuple(x, y, z, 0.0)
{
}

double Vector::magnitude() const
{
    return std::sqrt(_x * _x + _y * _y + _z * _z);
}

Vector Vector::normalize() const
{
    return Vector(_x / magnitude(),
                  _y / magnitude(),
                  _z / magnitude());
}

double Vector::dot(const Vector& rhs) const
{
    return _x * rhs._x + _y * rhs._y + _z * rhs._z;
}

Vector Vector::cross(const Vector& rhs) const
{
    return Vector(_y * rhs._z - _z * rhs._y,
                  _z * rhs._x - _x * rhs._z,
                  _x * rhs._y - _y * rhs._x);
}