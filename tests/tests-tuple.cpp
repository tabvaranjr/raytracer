#include <ostream>
#include "catch2/catch.hpp"

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

SCENARIO("Adding two tuples")
{
    GIVEN("a1 <- tuple(3, -2, 5, 1)")
    AND_GIVEN("a2 <- tuple(-2, 3, 1, 0)")
    {
        THEN("a1 + a2 = tuple(1, 1, 6, 1)")
        {
            FAIL();
        }
    }
}

SCENARIO("Subtracting two points")
{
    GIVEN("p1 <- point(3, 2, 1)")
    AND_GIVEN("p2 <- point(5, 6, 7)")
    {
        THEN("p1 - p2 = vector(-2, -4, -6)")
        {
            FAIL();
        }
    }
}

SCENARIO("Substracting a vector from a point")
{
    GIVEN("p <- point(3, 2, 1)")
    AND_GIVEN("v <- vector(5, 6, 7)")
    {
        THEN("p - v = point(-2, -4, -6)")
        {
            FAIL();
        }
    }
}

SCENARIO("Substracting two vectors")
{
    GIVEN("v1 <- vector(3, 2, 1)")
    AND_GIVEN("v2 <- vector(5, 6, 7)")
    {
        THEN("v1 - v2 = vector(-2, -4, -6)")
        {
            FAIL();
        }
    }
}

SCENARIO("Substracting a vector from the zero vector")
{
    GIVEN("zero <- vector(0, 0, 0)")
    AND_GIVEN("v <- vector(1, -2, 3)")
    {
        THEN("zero - v <- vector(-1, 2, -3)")
        {
            FAIL();
        }
    }
}

SCENARIO("Negating a tuple")
{
    GIVEN("a <- tuple(1, -2, 3, -4)")
    {
        THEN("-a <- tuple(-1, 2, -3, 4)")
        {
            FAIL();
        }
    }
}

SCENARIO("Multiplying a tuple by a scalar")
{
    GIVEN("a <- tuple(1, -2, 3, -4)")
    {
        THEN("a * 3.5 = tuple(3.5, -7, 10.5, -14)")
        {
            FAIL();
        }
    }
}

SCENARIO("Multiplying a tuple by a fraction")
{
    GIVEN("a <- tuple(1, -2, 3, -4)")
    {
        THEN("a * 0.5 = tuple(0.5, -1, 1.5, -2)")
        {
            FAIL();
        }
    }
}

SCENARIO("Dividing a tuple by a scalar")
{
    GIVEN("a <- tuple(1, -2, 3, -4)")
    {
        THEN("a / 2 = tuple(0.5, -1, 1.5, -2)")
        {
            FAIL();
        }
    }
}

SCENARIO("Computing the magnitude of vector(1, 0, 0)")
{
    GIVEN("v <- vector(1, 0, 0)")
    {
        THEN("magnitude(v) = 1")
        {
            FAIL();
        }
    }
}

SCENARIO("Computing the magnitude of vector(0, 1, 0)")
{
    GIVEN("v <- vector(0, 1, 0)")
    {
        THEN("magnitude(v) = 1")
        {
            FAIL();
        }
    }
}

SCENARIO("Computing the magnitude of vector(0, 0, 1)")
{
    GIVEN("v <- vector(0, 0, 1)")
    {
        THEN("magnitude(v) = 1")
        {
            FAIL();
        }
    }
}

SCENARIO("Computing the magnitude of vector(1, 2, 3)")
{
    GIVEN("v <- vector(1, 2, 3)")
    {
        THEN("magnitude(v) = √14")
        {
            FAIL();
        }
    }
}

SCENARIO("Computing the magnitude of vector(-1, -2, -3)")
{
    GIVEN("v <- vector(-1, -2, -3)")
    {
        THEN("magnitude(v) = √14")
        {
            FAIL();
        }
    }
}

SCENARIO("Normalizing vector(4, 0, 0) gives (1, 0, 0)")
{
    GIVEN("v <- vector(4, 0, 0)")
    {
        THEN("normalize(v) = vector(1, 0, 0)")
        {
            FAIL();
        }
    }
}

SCENARIO("Normalizing vector(1, 2, 3)")
{
    GIVEN("v <- vector(1, 2, 3)")
    {
        THEN("normalize(v) = approximately vector(0.26726, 0.53452, 0.80178)")
        {
            FAIL();
        }
    }
}

SCENARIO("The magnitude of a normalized vector")
{
    GIVEN("v <- vector(1, 2, 3)")
    {
        WHEN("norm <- normalize(v)")
        THEN("magnitude(norm) = 1")
        {
            FAIL();
        }
    }
}

SCENARIO("The dot product of two tuples")
{
    GIVEN("a <- vector(1, 2, 3)")
    AND_GIVEN("b <- vector(2, 3, 4)")
    {
        THEN("dot(a, b) = 20")
        {
            FAIL();
        }
    }
}

SCENARIO("The cross product of two vectors")
{
    GIVEN("a <- vector(1, 2, 3)")
    AND_GIVEN("b <- vector(2, 3, 4)")
    {
        THEN("cross(a, b) = vector(-1, 2, -1)")
        {
            FAIL();
        }
        
        AND_THEN("cross(b, a) = vector(1, -2, 1)")
        {
            FAIL();
        }
    }
}

