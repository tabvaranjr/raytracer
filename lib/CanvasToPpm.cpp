#include "CanvasToPpm.h"

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <algorithm>
#include <cmath>
#include "Canvas.h"
#include "Color.h"

void CanvasToPpm::header(std::ostream& os, const Canvas& c)
{
    fmt::print(os, "P3\n");
    fmt::print(os, "{} {}\n", c.width(), c.height());
    fmt::print(os, "255\n");
}

void CanvasToPpm::data(std::ostream& os, const Canvas& c)
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

                if (length != 0)
                    fmt::print(os, " ");
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

                if (length != 0)
                    fmt::print(os, " ");
                fmt::print(os, entry);

                length += entry.length() + 1;
            }

            {
                auto entry = std::to_string(saturate(px.blue() * 255, 0, 255));
                if (length + entry.length() + 1 > 70)
                {
                    fmt::print(os, "\n");
                    length = 0;
                }

                if (length != 0)
                    fmt::print(os, " ");
                fmt::print(os, entry);

                length += entry.length() + 1;
            }
        }

        fmt::print(os, "\n");
    }
}

int CanvasToPpm::saturate(double v, int min, int max)
{
    return std::clamp<int>(std::round(v), min, max);
}
