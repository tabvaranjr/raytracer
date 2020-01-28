#pragma once

#include <ostream>
#include <cmath>

const double EPSILON = 1e-6;
bool isEqual(double a, double b);

class Tuple
{
public:
    Tuple(double x, double y, double z, double w);

    double x();
    double y();
    double z();
    double w();

    bool isPoint();
    bool isVector();

    bool operator==(const Tuple& rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const Tuple& tuple);

private:
    double _x;
    double _y;
    double _z;
    double _w;
};


