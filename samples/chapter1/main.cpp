#include <fmt/format.h>
#include "Point.h"
#include "Vector.h"

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

Point operator+(const Point& p, const Vector& v)
{
    return {p.x() + v.x(), p.y() + v.y(), p.z() + v.z()};
}

Vector operator+(const Vector& v1, const Vector& v2)
{
    return {v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v1.z()};
}

Projectile tick(Environment env, Projectile proj)
{
    Point position(0, 0, 0);

    position = proj.position + proj.velocity;
    Vector velocity = proj.velocity + env.gravity + env.wind;

    return {position, velocity};
};

template <>
struct fmt::formatter<Point>
{
    template <typename ParseContext>
    constexpr auto parse(ParseContext& ctx)
    {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(Point const& p, FormatContext& ctx)
    {
        return fmt::format_to(ctx.out(), "({}, {}, {})", p.x(), p.y(), p.z());
    }
};

template <>
struct fmt::formatter<Vector>
{
    template <typename ParseContext>
    constexpr auto parse(ParseContext& ctx)
    {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(Vector const& v, FormatContext& ctx)
    {
        return fmt::format_to(ctx.out(), "({}, {}, {})", v.x(), v.y(), v.z());
    }
};

int main()
{
    Environment e{Vector(0, -0.1, 0), Vector(-0.01, 0, 0)};
    Projectile p{Point(0, 1, 0), Vector(1, 1, 0).normalize()};

    fmt::print("Environment => gravity: {}, wind: {}\n", e.gravity, e.wind);
    fmt::print("Projectile => position: {}, velocity: {}\n", p.position, p.velocity);

    auto count = 1UL;
    while (p.position.y() >= 0)
    {
        p = tick(e, p);
        fmt::print("Tick {}: position: {}, velocity: {}\n", count, p.position, p.velocity);
        count++;
    }

    return 0;
}
