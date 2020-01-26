#include <ostream>
#include "catch.hpp"

const double EPSILON = 1e-6;
bool isEqual(double a, double b)
{
    return std::abs(a - b) < EPSILON;
}

class Tuple
{
public:
    Tuple(double x, double y, double z, double w) :
        _x(x), _y(y), _z(z), _w(w)
    {
    }

    double x()
    {
        return _x;
    }

    double y()
    {
        return _y;
    }

    double z()
    {
        return _z;
    }

    double w()
    {
        return _w;
    }

    bool isPoint()
    {
        return _w == 1.0;
    }

    bool isVector()
    {
        return _w == 0.0;
    }

    bool operator==(const Tuple& rhs) const
    {
        return isEqual(_x, rhs._x) &&
               isEqual(_y, rhs._y) &&
               isEqual(_z, rhs._z) &&
               isEqual(_w, rhs._w);
    }

    friend std::ostream& operator<<(std::ostream& os, const Tuple& tuple)
    {
        os << "(" << tuple._x << ", " << tuple._y << ", " << tuple._z << ", " << tuple._w << ")";
        return os;
    }

private:
    double _x;
    double _y;
    double _z;
    double _w;
};

class Point : public Tuple
{
public:
    Point(double x, double y, double z) :
        Tuple(x, y, z, 1.0)
    {
    }
};

class Vector : public Tuple
{
public:
    Vector(double x, double y, double z) :
            Tuple(x, y, z, 0.0)
    {
    }
};

SCENARIO("A tuple with w=1.0 is a point")
{
    GIVEN("a <- tuple(4.3, -4.2, 3.1, 1.0)" )
    {
        Tuple a(4.3, -4.2, 3.1, 1.0);

        THEN("a.x = 4.3")
        {
            REQUIRE(a.x() == 4.3);
        }

        AND_THEN("a.y = -4.2")
        {
            REQUIRE(a.y() == -4.2);
        }

        AND_THEN("a.z = 3.1")
        {
            REQUIRE(a.z() == 3.1);
        }

        AND_THEN("a.w = 1.0")
        {
            REQUIRE(a.w() == 1.0);
        }

        AND_THEN("a is a point")
        {
            REQUIRE(a.isPoint());
        }

        AND_THEN("a is not a vector")
        {
            REQUIRE(!a.isVector());
        }
    }
}

SCENARIO("A tuple with w=0.0 is a vector")
{
    GIVEN("a <- tuple(4.3, -4.2, 3.1, 0.0)" )
    {
        Tuple a(4.3, -4.2, 3.1, 0.0);

        THEN("a.x = 4.3")
        {
            REQUIRE(a.x() == 4.3);
        }

        AND_THEN("a.y = -4.2")
        {
            REQUIRE(a.y() == -4.2);
        }

        AND_THEN("a.z = 3.1")
        {
            REQUIRE(a.z() == 3.1);
        }

        AND_THEN("a.w = 0.0")
        {
            REQUIRE(a.w() == 0.0);
        }

        AND_THEN("a is not a point")
        {
            REQUIRE(!a.isPoint());
        }

        AND_THEN("a is a vector")
        {
            REQUIRE(a.isVector());
        }
    }
}

SCENARIO("point() create tuples with w=1")
{
    Point p(4, -4, 3);

    GIVEN("p <- point(4, -4, 3)")
    {
        THEN("p = tuple(4, -4, 3, 1)")
        {
            Tuple t(4, -4, 3, 1);

            REQUIRE(p == t);
        }
    }
}

SCENARIO("vector() create tuples with w=0")
{
    Vector v(4, -4, 3);

    GIVEN("v <- vector(4, -4, 3)")
    {
        THEN("v = tuple(4, -4, 3, 0)")
        {
            Tuple t(4, -4, 3, 0);

            REQUIRE(v == t);
        }
    }
}