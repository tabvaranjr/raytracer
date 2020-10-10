#include "Point.h"

Point::Point(double x, double y, double z)
    : Tuple(x, y, z, 1.0)
{
}

Point::Point(const Tuple& t)
{
    _x = t.x();
    _y = t.y();
    _z = t.z();
    _w = t.w();
}
