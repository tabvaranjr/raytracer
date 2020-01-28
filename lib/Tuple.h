#pragma once

#include <ostream>
#include <cmath>

const double EPSILON = 1e-6;
bool isEqual(double a, double b);

class Tuple
{
public:
    Tuple(double x, double y, double z, double w);

    double x() const;
    double y() const;
    double z() const;
    double w() const;

    bool isPoint() const;
    bool isVector() const;

    bool operator==(const Tuple& rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const Tuple& tuple);

private:
    double _x;
    double _y;
    double _z;
    double _w;
};


