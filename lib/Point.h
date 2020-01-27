#pragma once

#include "Tuple.h"

class Point : public Tuple
{
public:
    Point(double x, double y, double z) :
        Tuple(x, y, z, 1.0)
    {
    }
};
