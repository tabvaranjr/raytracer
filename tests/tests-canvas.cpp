#include <catch2/catch.hpp>

SCENARIO("Creating a canvas")
{
    GIVEN("c <- canvas(10, 20)")
    {
        THEN("c.width = 10")
        {
            FAIL();
        }
        AND_THEN("c.height = 20")
        {
            FAIL();
        }
        AND_THEN("every pixel of c is color(0, 0, 0)")
        {
            FAIL();
        }
    }
}

SCENARIO("Writing pixels to a canvas")
{
    GIVEN("c <- canvas(10, 20)")
    AND_GIVEN("red <- color(1, 0, 0)")
    {
        WHEN("write_pixel(c, 2, 3, red)")
        THEN("pixel_at(c, 2, 3) = red")
        {
            FAIL();
        }
    }
}

SCENARIO("Constructing the PPM header")
{
    GIVEN("c <- canvas(5, 3)")
    {
        WHEN("ppm <- canvas_to_ppm(c)")
        THEN(R"(lines 1-3 of ppm are 
        P3
        5 3
        255
        )")
        {
            FAIL();
        }
    }
}

SCENARIO("Constructing the PPM pixel data")
{
    GIVEN("c <- canvas(5,3)")
    AND_GIVEN("c1 <- color(1.5, 0, 0)")
    AND_GIVEN("c2 <- color(0, 0.5, 0)")
    AND_GIVEN("c3 <- color(-0.5, 0, 1)")
    {
        WHEN("write_pixel(c, 0, 0, c1)")
        AND_WHEN("write_pixel(c, 2, 1, c2)")
        AND_WHEN("write_pixel(c, 4, 2, c3)")
        AND_WHEN("ppm <- canvas_to_ppm(c)")
        THEN(R"(lines 4-6 of ppm are
        255 0 0 0 0 0 0 0 0 0 0 0 0 0 0
        0 0 0 0 0 0 0 128 0 0 0 0 0 0 0
        0 0 0 0 0 0 0 0 0 0 0 0 0 0 255
        )")
        {
            FAIL();
        }
    }
}

SCENARIO("Splitting long lines in PPM files")
{
    GIVEN("c <- canvas(10, 2)")
    {
        WHEN("every pixel of c is set to color(1, 0.8, 0,6)")
        AND_WHEN("ppm <- canvas_to_ppm(c)")
        THEN(R"(lines 4-7 of ppm are
        255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204 
        153 255 204 153 255 204 153 255 204 153 255 204 153 
        255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204 
        153 255 204 153 255 204 153 255 204 153 255 204 153 
        )")
        {
            FAIL();
        }
    }
}

SCENARIO("PPM files are terminated by a newline character")
{
    GIVEN("c <- canvas(5, 3)")
    {
        WHEN("ppm <- canvas_to_ppm(c)")
        THEN("ppm ends with a newline character")
        {
            FAIL();
        }
    }
}
