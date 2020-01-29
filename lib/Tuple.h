#pragma once

#include <ostream>

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

    Tuple operator-() const;

    Tuple operator+(const Tuple& rhs) const;
    Tuple operator-(const Tuple& rhs) const;
    Tuple operator*(double rhs) const;
    Tuple operator/(double rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const Tuple& tuple);

protected:
    double _x;
    double _y;
    double _z;
    double _w;
};
