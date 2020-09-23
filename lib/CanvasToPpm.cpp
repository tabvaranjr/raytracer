#include "CanvasToPpm.h"

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <algorithm>
#include <cmath>
#include "Canvas.h"
#include "Color.h"

constexpr int MaxLength = 70;

int saturate(double v, int min, int max)
{
    return std::clamp<int>(std::round(v), min, max);
}

CanvasToPpm::CanvasToPpm()
    : _lineLength(0)
{
}

void CanvasToPpm::header(std::ostream& os, const Canvas& c)
{
    fmt::print(os, "P3\n");
    fmt::print(os, "{} {}\n", c.width(), c.height());
    fmt::print(os, "255\n");
}

void CanvasToPpm::data(std::ostream& os, const Canvas& c)
{
    CanvasToPpm conv;

    for (auto h = 0; h < c.height(); h++)
    {
        conv.resetLineLength();

        for (auto w = 0; w < c.width(); w++)
        {
            const auto& px = c.pixel(w, h);
            conv.writePixel(os, px);
        }

        fmt::print(os, "\n");
    }
}

void CanvasToPpm::resetLineLength()
{
    _lineLength = 0;
}

void CanvasToPpm::writePixel(std::ostream& os, const Color& px)
{
    writeChannel(os, px.red());
    writeChannel(os, px.green());
    writeChannel(os, px.blue());
}

void CanvasToPpm::writeChannel(std::ostream& os, double c)
{
    auto entry = std::to_string(saturate(c * 255, 0, 255));
    if (_lineLength + entry.length() + 1 > MaxLength)
    {
        fmt::print(os, "\n");
        resetLineLength();
    }

    if (_lineLength != 0)
    {
        fmt::print(os, " ");
    }

    fmt::print(os, entry);
    _lineLength += entry.length() + 1;
}
