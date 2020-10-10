#include <fmt/format.h>
#include "Canvas.h"
#include "Point.h"
#include "Vector.h"
#include "CanvasToPpm.h"

#include <fstream>

struct Projectile
{
    Point position;
    Vector velocity;
};

struct Environment
{
    Vector gravity;
    Vector wind;
};

Projectile tick(Environment env, Projectile proj)
{
    Point position(0, 0, 0);

    position = proj.position + proj.velocity;
    Vector velocity = proj.velocity + env.gravity + env.wind;

    return {position, velocity};
};

constexpr bool isPointInsideCanvas(const Point& pos, const Canvas& c)
{
    return pos.x() >= 0 &&
           pos.x() < c.width() &&
           pos.y() >= 0 &&
           pos.y() < c.height();
}

int main()
{
    Point start(0, 1, 0);
    Environment e{Vector(0, -0.1, 0), Vector(-0.01, 0, 0)};
    Projectile p{Point(0, 1, 0), Vector(1, 1.8, 0).normalize() * 11.25};

    Canvas c(900, 550);

    auto count = 1UL;
    while (isPointInsideCanvas(p.position, c))
    {
        fmt::print("Tick {}: position: {}, velocity: {}\n", count, p.position, p.velocity);
        c.setPixel(p.position.x(), c.height() - p.position.y(), Color(1, 0, 0));

        p = tick(e, p);
        count++;
    }

    std::ofstream file("chapter2.ppm");
    CanvasToPpm::header(file, c);
    CanvasToPpm::data(file, c);

    return 0;
}
