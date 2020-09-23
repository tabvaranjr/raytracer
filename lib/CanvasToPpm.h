#include <iosfwd>

class Canvas;
class Color;

class CanvasToPpm
{
public:
    static void header(std::ostream& os, const Canvas& c);
    static void data(std::ostream& os, const Canvas& c);

private:
    CanvasToPpm();

    void resetLineLength();
    void writePixel(std::ostream& os, const Color& p);
    void writeChannel(std::ostream& os, double c);

    int _lineLength;
};
