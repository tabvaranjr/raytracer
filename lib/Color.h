#pragma once

#include "Tuple.h"

class Color : public Tuple
{
public:
    Color(double r, double g, double b);

    double red() const;
    double green() const;
    double blue() const;

    Color hadamard(const Color& rhs) const;
};
