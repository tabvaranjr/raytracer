#include "Math.h"

#include <cmath>

bool isApproxEqual(double a, double b, double epsilon)
{
    return std::abs(a - b) < epsilon;
}
