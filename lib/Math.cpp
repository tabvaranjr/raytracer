#include "Math.h"

#include <cmath>

bool isEqual(double a, double b, double epsilon)
{
    return std::abs(a - b) < epsilon;
}
