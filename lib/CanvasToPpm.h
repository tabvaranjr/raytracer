#include <iosfwd>

class Canvas;

class CanvasToPpm
{
public:
    static void header(std::ostream& os, const Canvas& c);
    static void data(std::ostream& os, const Canvas& c);
    static int saturate(double v, int min, int max);
};
