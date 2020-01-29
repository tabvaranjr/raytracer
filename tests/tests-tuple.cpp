#include <catch2/catch.hpp>

#include "Point.h"
#include "Tuple.h"
#include "Vector.h"

SCENARIO("A tuple with w=1.0 is a point")
{
    GIVEN("a <- tuple(4.3, -4.2, 3.1, 1.0)")
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
    GIVEN("a <- tuple(4.3, -4.2, 3.1, 0.0)")
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
    GIVEN("p <- point(4, -4, 3)")
    {
        Point p(4, -4, 3);

        THEN("p = tuple(4, -4, 3, 1)")
        {
            Tuple t(4, -4, 3, 1);

            REQUIRE(p == t);
        }
    }
}

SCENARIO("vector() create tuples with w=0")
{
    GIVEN("v <- vector(4, -4, 3)")
    {
        Vector v(4, -4, 3);

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
        Tuple a1(3, -2, 5, 1);
        Tuple a2(-2, 3, 1, 0);

        THEN("a1 + a2 = tuple(1, 1, 6, 1)")
        {
            Tuple t(1, 1, 6, 1);

            REQUIRE((a1 + a2) == t);
        }
    }
}

SCENARIO("Subtracting two points")
{
    GIVEN("p1 <- point(3, 2, 1)")
    AND_GIVEN("p2 <- point(5, 6, 7)")
    {
        Point p1(3, 2, 1);
        Point p2(5, 6, 7);

        THEN("p1 - p2 = vector(-2, -4, -6)")
        {
            Vector t(-2, -4, -6);

            REQUIRE((p1 - p2) == t);
        }
    }
}

SCENARIO("Subtracting a vector from a point")
{
    GIVEN("p <- point(3, 2, 1)")
    AND_GIVEN("v <- vector(5, 6, 7)")
    {
        Point p(3, 2, 1);
        Vector v(5, 6, 7);

        THEN("p - v = point(-2, -4, -6)")
        {
            Point t(-2, -4, -6);

            REQUIRE((p - v) == t);
        }
    }
}

SCENARIO("Subtracting two vectors")
{
    GIVEN("v1 <- vector(3, 2, 1)")
    AND_GIVEN("v2 <- vector(5, 6, 7)")
    {
        Vector v1(3, 2, 1);
        Vector v2(5, 6, 7);

        THEN("v1 - v2 = vector(-2, -4, -6)")
        {
            Vector t(-2, -4, -6);

            REQUIRE((v1 - v2) == t);
        }
    }
}

SCENARIO("Subtracting a vector from the zero vector")
{
    GIVEN("zero <- vector(0, 0, 0)")
    AND_GIVEN("v <- vector(1, -2, 3)")
    {
        Vector zero(0, 0, 0);
        Vector v(1, -2, 3);

        THEN("zero - v <- vector(-1, 2, -3)")
        {
            Vector t(-1, 2, -3);

            REQUIRE((zero - v) == t);
        }
    }
}

SCENARIO("Negating a tuple")
{
    GIVEN("a <- tuple(1, -2, 3, -4)")
    {
        Tuple a(1, -2, 3, -4);

        THEN("-a <- tuple(-1, 2, -3, 4)")
        {
            Tuple t(-1, 2, -3, 4);

            REQUIRE(-a == t);
        }
    }
}

SCENARIO("Multiplying a tuple by a scalar")
{
    GIVEN("a <- tuple(1, -2, 3, -4)")
    {
        Tuple a(1, -2, 3, -4);

        THEN("a * 3.5 = tuple(3.5, -7, 10.5, -14)")
        {
            Tuple t(3.5, -7, 10.5, -14);

            REQUIRE(a * 3.5 == t);
        }
    }
}

SCENARIO("Multiplying a tuple by a fraction")
{
    GIVEN("a <- tuple(1, -2, 3, -4)")
    {
        Tuple a(1, -2, 3, -4);

        THEN("a * 0.5 = tuple(0.5, -1, 1.5, -2)")
        {
            Tuple t(0.5, -1, 1.5, -2);

            REQUIRE(a * 0.5 == t);
        }
    }
}

SCENARIO("Dividing a tuple by a scalar")
{
    GIVEN("a <- tuple(1, -2, 3, -4)")
    {
        Tuple a(1, -2, 3, -4);

        THEN("a / 2 = tuple(0.5, -1, 1.5, -2)")
        {
            Tuple t(0.5, -1, 1.5, -2);

            REQUIRE(a / 2 == t);
        }
    }
}

SCENARIO("Computing the magnitude of vector(1, 0, 0)")
{
    GIVEN("v <- vector(1, 0, 0)")
    {
        Vector v(1, 0, 0);

        THEN("magnitude(v) = 1")
        {
            REQUIRE(v.magnitude() == 1);
        }
    }
}

SCENARIO("Computing the magnitude of vector(0, 1, 0)")
{
    GIVEN("v <- vector(0, 1, 0)")
    {
        Vector v(0, 1, 0);

        THEN("magnitude(v) = 1")
        {
            REQUIRE(v.magnitude() == 1);
        }
    }
}

SCENARIO("Computing the magnitude of vector(0, 0, 1)")
{
    GIVEN("v <- vector(0, 0, 1)")
    {
        Vector v(0, 0, 1);

        THEN("magnitude(v) = 1")
        {
            REQUIRE(v.magnitude() == 1);
        }
    }
}

SCENARIO("Computing the magnitude of vector(1, 2, 3)")
{
    GIVEN("v <- vector(1, 2, 3)")
    {
        Vector v(1, 2, 3);

        THEN("magnitude(v) = √14")
        {
            REQUIRE(v.magnitude() == std::sqrt(14));
        }
    }
}

SCENARIO("Computing the magnitude of vector(-1, -2, -3)")
{
    GIVEN("v <- vector(-1, -2, -3)")
    {
        Vector v(-1, -2, -3);

        THEN("magnitude(v) = √14")
        {
            REQUIRE(v.magnitude() == std::sqrt(14));
        }
    }
}

SCENARIO("Normalizing vector(4, 0, 0) gives (1, 0, 0)")
{
    GIVEN("v <- vector(4, 0, 0)")
    {
        Vector v(4, 0, 0);

        THEN("normalize(v) = vector(1, 0, 0)")
        {
            Vector t(1, 0, 0);
            
            REQUIRE(v.normalize() == t);
        }
    }
}

SCENARIO("Normalizing vector(1, 2, 3)")
{
    GIVEN("v <- vector(1, 2, 3)")
    {
        Vector v(1, 2, 3);

        THEN("normalize(v) = vector(1/√14, 2/√14, 3/√14)")
        {
            Vector t(1 / std::sqrt(14), 2 / std::sqrt(14), 3 / std::sqrt(14));

            REQUIRE(v.normalize() == t);
        }
    }
}

SCENARIO("The magnitude of a normalized vector")
{
    GIVEN("v <- vector(1, 2, 3)")
    {
        Vector v(1, 2, 3);

        WHEN("norm <- normalize(v)")
        THEN("magnitude(norm) = 1")
        {
            Vector norm = v.normalize();

            REQUIRE(norm.magnitude() == 1);
        }
    }
}

SCENARIO("The dot product of two tuples")
{
    GIVEN("a <- vector(1, 2, 3)")
    AND_GIVEN("b <- vector(2, 3, 4)")
    {
        Vector a(1, 2, 3);
        Vector b(2, 3, 4);

        THEN("dot(a, b) = 20")
        {
            REQUIRE(a.dot(b) == 20);
        }
    }
}

SCENARIO("The cross product of two vectors")
{
    GIVEN("a <- vector(1, 2, 3)")
    AND_GIVEN("b <- vector(2, 3, 4)")
    {
        Vector a(1, 2, 3);
        Vector b(2, 3, 4);

        THEN("cross(a, b) = vector(-1, 2, -1)")
        {
            Vector t(-1, 2, -1);

            REQUIRE(a.cross(b) == t);
        }

        AND_THEN("cross(b, a) = vector(1, -2, 1)")
        {
            Vector t(1, -2, 1);

            REQUIRE(b.cross(a) == t);
        }
    }
}
