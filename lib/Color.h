#pragma once

#include "Tuple.h"

class Color : public Tuple
{
public:
    Color(double r, double g, double b);

    double red();
    double green();
    double blue();

    Color hadamard(const Color& rhs) const;
};
