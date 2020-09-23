#include <catch2/catch.hpp>

#include <sstream>
#include "Color.h"
#include "Canvas.h"
#include "CanvasToPpm.h"

SCENARIO("Creating a canvas")
{
    GIVEN("c <- canvas(10, 20)")
    {
        Canvas c(10, 20);

        THEN("c.width = 10")
        {
            REQUIRE(c.width() == 10);
        }
        AND_THEN("c.height = 20")
        {
            REQUIRE(c.height() == 20);
        }
        AND_THEN("every pixel of c is color(0, 0, 0)")
        {
            for (auto h = 0; h < c.height(); h++)
            {
                for (auto w = 0; w < c.width(); w++)
                {
                    REQUIRE(c.pixel(w, h) == Color(0.0, 0.0, 0.0));
                }
            }
        }
    }
}

SCENARIO("Writing pixels to a canvas")
{
    GIVEN("c <- canvas(10, 20)")
    AND_GIVEN("red <- color(1, 0, 0)")
    {
        Canvas c(10, 20);
        Color red(1.0, 0.0, 0.0);

        WHEN("write_pixel(c, 2, 3, red)")
        THEN("pixel_at(c, 2, 3) = red")
        {
            c.setPixel(2, 3, Color(1, 0, 0));
            REQUIRE(c.pixel(2, 3) == red);
        }
    }
}

SCENARIO("Constructing the PPM header")
{
    GIVEN("c <- canvas(5, 3)")
    {
        Canvas c(5, 3);

        WHEN("ppm <- canvas_to_ppm(c)")
        THEN(R"(lines 1-3 of ppm are 
        P3
        5 3
        255
        )")
        {
            std::stringstream expected;
            expected << "P3" << std::endl
                     << "5 3" << std::endl
                     << "255" << std::endl;

            std::stringstream actual;
            CanvasToPpm::header(actual, c);

            REQUIRE(actual.str() == expected.str());
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
        Canvas c(5, 3);
        Color c1(1.5, 0.0, 0.0);
        Color c2(0.0, 0.5, 0.0);
        Color c3(-0.5, 0.0, 1.0);

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
            std::stringstream expected;
            expected << "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0" << std::endl;
            expected << "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0" << std::endl;
            expected << "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255" << std::endl;

            c.setPixel(0, 0, c1);
            c.setPixel(2, 1, c2);
            c.setPixel(4, 2, c3);

            std::stringstream actual;
            CanvasToPpm::data(actual, c);

            REQUIRE(actual.str() == expected.str());
        }
    }
}

SCENARIO("Splitting long lines in PPM files")
{
    GIVEN("c <- canvas(10, 2)")
    {
        Canvas c(10, 2);

        WHEN("every pixel of c is set to color(1, 0.8, 0,6)")
        AND_WHEN("ppm <- canvas_to_ppm(c)")
        THEN(R"(lines 4-7 of ppm are
        255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204 
        153 255 204 153 255 204 153 255 204 153 255 204 153 
        255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204 
        153 255 204 153 255 204 153 255 204 153 255 204 153 
        )")
        {
            std::stringstream expected;
            expected << "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204" << std::endl;
            expected << "153 255 204 153 255 204 153 255 204 153 255 204 153" << std::endl;
            expected << "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204" << std::endl;
            expected << "153 255 204 153 255 204 153 255 204 153 255 204 153" << std::endl;

            c.clearTo(Color(1.0, 0.8, 0.6));

            std::stringstream actual;
            CanvasToPpm::data(actual, c);

            REQUIRE(actual.str() == expected.str());
        }
    }
}

SCENARIO("PPM files are terminated by a newline character")
{
    GIVEN("c <- canvas(5, 3)")
    {
        Canvas c(5, 3);

        WHEN("ppm <- canvas_to_ppm(c)")
        THEN("ppm ends with a newline character")
        {
            std::stringstream actual;
            CanvasToPpm::data(actual, c);

            REQUIRE(*(actual.str().rbegin()) == '\n');
        }
    }
}
