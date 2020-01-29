#pragma once

#include "Tuple.h"

class Vector : public Tuple
{
public:
    Vector(double x, double y, double z);

    double magnitude() const;

    Vector normalize() const;

    double dot(const Vector& rhs) const;

    Vector cross(const Vector& rhs) const;
};
