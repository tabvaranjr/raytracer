#pragma once

#include <ostream>
#include <cmath>

const double EPSILON = 1e-6;
bool isEqual(double a, double b)
{
    return std::abs(a - b) < EPSILON;
}

class Tuple
{
public:
    Tuple(double x, double y, double z, double w) :
        _x(x), _y(y), _z(z), _w(w)
    {
    }

    double x()
    {
        return _x;
    }

    double y()
    {
        return _y;
    }

    double z()
    {
        return _z;
    }

    double w()
    {
        return _w;
    }

    bool isPoint()
    {
        return _w == 1.0;
    }

    bool isVector()
    {
        return _w == 0.0;
    }

    bool operator==(const Tuple& rhs) const
    {
        return isEqual(_x, rhs._x) &&
               isEqual(_y, rhs._y) &&
               isEqual(_z, rhs._z) &&
               isEqual(_w, rhs._w);
    }

    friend std::ostream& operator<<(std::ostream& os, const Tuple& tuple)
    {
        os << "(" << tuple._x << ", " << tuple._y << ", " << tuple._z << ", " << tuple._w << ")";
        return os;
    }

private:
    double _x;
    double _y;
    double _z;
    double _w;
};


