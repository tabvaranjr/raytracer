#pragma once

#include "Tuple.h"

class Vector : public Tuple
{
public:
    Vector(double x, double y, double z) :
        Tuple(x, y, z, 0.0)
    {
    }
};
