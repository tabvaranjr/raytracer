#include <catch2/catch.hpp>

#include "Color.h"

SCENARIO("Colors are (red, green, blue) tuples")
{
    GIVEN("c <- color(-0.5, 0.4, 1.7")
    {
        Color c(-0.5, 0.4, 1.7);

        THEN("c.red = -0.5")
        {
            REQUIRE(c.red() == -0.5);
        }
        AND_THEN("c.green = 0.4")
        {
            REQUIRE(c.green() == 0.4);
        }
        AND_THEN("c.blue = 1.7")
        {
            REQUIRE(c.blue() == 1.7);
        }
    }
}

SCENARIO("Adding colors")
{
    GIVEN("c1 <- color(0.9, 0.6, 0.75)")
    AND_GIVEN("c2 <- color(0.7, 0.1, 0.25)")
    {
        Color c1(0.9, 0.6, 0.75);
        Color c2(0.7, 0.1, 0.25);

        THEN("c1 + c2 = color(1.6, 0.7, 1.0)")
        {
            REQUIRE((c1 + c2) == Color(1.6, 0.7, 1.0));
        }
    }
}

SCENARIO("Subtracting colors")
{
    GIVEN("c1 <- color(0.9, 0.6, 0.75)")
    AND_GIVEN("c2 <- color(0.7, 0.1, 0.25)")
    {
        Color c1(0.9, 0.6, 0.75);
        Color c2(0.7, 0.1, 0.25);

        THEN("c1 - c2 = color(0.2, 0.5, 0.5)")
        {
            REQUIRE((c1 - c2) == Color(0.2, 0.5, 0.5));
        }
    }
}

SCENARIO("Multiplying a color by a scalar")
{
    GIVEN("c <- color(0.2, 0.3, 0.4)")
    {
        Color c(0.2, 0.3, 0.4);

        THEN("c * 2 = color(0.4, 0.6, 0.8)")
        {
            REQUIRE(c * 2.0 == Color(0.4, 0.6, 0.8));
        }
    }
}

SCENARIO("Multiplying colors")
{
    GIVEN("c1 <- color(1, 0.2, 0.4)")
    AND_GIVEN("c2 <- color(0.9, 1, 0.1)")
    {
        Color c1(1.0, 0.2, 0.4);
        Color c2(0.9, 1.0, 0.1);

        THEN("c1 * c2 = color(0.9, 0.2, 0.04)")
        {
            REQUIRE(c1.hadamard(c2) == Color(0.9, 0.2, 0.04));
        }
    }
}
