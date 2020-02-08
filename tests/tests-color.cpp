#include <catch2/catch.hpp>

SCENARIO("Colors are (red, green, blue) tuples")
{
    GIVEN("c <- color(-0.5, 0.4, 1.7")
    {
        THEN("c.red = -0.5")
        {
            FAIL();
        }
        AND_THEN("c.green = 0.4")
        {
            FAIL();
        }
        AND_THEN("c.blue = 1.7")
        {
            FAIL();
        }
    }
}

SCENARIO("Adding colors")
{
    GIVEN("c1 <- color(0.9, 0.6, 0.75)")
    AND_GIVEN("c2 <- color(0.7, 0.1, 0.25)")
    THEN("c1 + c2 = color(1.6, 0.7, 1.0)")
    {
        FAIL();
    }
}

SCENARIO("Subtracting colors")
{
    GIVEN("c1 <- color(0.9, 0.6, 0.75)")
    AND_GIVEN("c2 <- color(0.7, 0.1, 0.25)")
    {
        THEN("c1 - c2 = color(0.2, 0.5, 0.5)")
        {
            FAIL();
        }
    }
}

SCENARIO("Multiplying a color by a scalar")
{
    GIVEN("c <- color(0.2, 0.3, 0.4)")
    {
        THEN("c * 2 = color(0.4, 0.6, 0.8)")
        {
            FAIL();
        }
    }
}

SCENARIO("Multiplying colors")
{
    GIVEN("c1 <- color(1, 0.2, 0.4)")
    AND_GIVEN("c2 <- color(0.9, 1, 0.1)")
    {
        THEN("c1 * c2 = color(0.9, 0.2, 0.04)")
        {
            FAIL();
        }
    }
}
