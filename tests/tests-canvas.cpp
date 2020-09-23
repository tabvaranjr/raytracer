#include <catch2/catch.hpp>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <algorithm>
#include <cmath>
#include <sstream>
#include "Color.h"

class Canvas
{
public:
    Canvas(int width, int height)
        : _width(width),
          _height(height),
          _pixels(_width * _height, Color(0, 0, 0))
    {
    }

    int width() const
    {
        return _width;
    }

    int height() const
    {
        return _height;
    }

    void clearTo(const Color& c)
    {
        std::fill(_pixels.begin(), _pixels.end(), c);
    }

    Color pixel(int w, int h) const
    {
        return _pixels.at(h * _width + w);
    }

    void setPixel(int w, int h, Color c)
    {
        _pixels.at(h * _width + w) = c;
    }

private:
    int _width;
    int _height;
    std::vector<Color> _pixels;
};

class CanvasToPpm
{
public:
    static void header(std::ostream& os, const Canvas& c)
    {
        fmt::print(os, "P3\n");
        fmt::print(os, "{} {}\n", c.width(), c.height());
        fmt::print(os, "255\n");
    }

    static void data(std::ostream& os, const Canvas& c)
    {
        for (auto h = 0; h < c.height(); h++)
        {
            auto length = 0;

            for (auto w = 0; w < c.width(); w++)
            {
                const auto& px = c.pixel(w, h);

                {
                    auto entry = std::to_string(saturate(px.red() * 255, 0, 255));
                    if (length + entry.length() + 1 > 70)
                    {
                        fmt::print(os, "\n");
                        length = 0;
                    }

                    if (length != 0) fmt::print(os, " ");
                    fmt::print(os, entry);
                    length += entry.length() + 1;
                }

                {
                    auto entry = std::to_string(saturate(px.green() * 255, 0, 255));
                    if (length + entry.length() + 1 > 70)
                    {
                        fmt::print(os, "\n");
                        length = 0;
                    }

                    if (length != 0) fmt::print(os, " ");
                    fmt::print(os, entry);
 
                    length += entry.length()  + 1;
                }

                {
                    auto entry = std::to_string(saturate(px.blue() * 255, 0, 255));
                    if (length + entry.length() + 1 > 70)
                    {
                        fmt::print(os, "\n");
                        length = 0;
                    }

                    if (length != 0) fmt::print(os, " ");
                    fmt::print(os, entry);
 
                    length += entry.length() + 1;
                }
            }

            fmt::print(os, "\n");
        }
    }

    static int saturate(double v, int min, int max)
    {
        return std::clamp<int>(std::round(v), min, max);
    }
};

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
