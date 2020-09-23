#include "Canvas.h"

#include "Color.h"

Canvas::Canvas(int width, int height)
    : _width(width),
      _height(height),
      _pixels(_width * _height, Color(0, 0, 0))
{
}

int Canvas::width() const
{
    return _width;
}

int Canvas::height() const
{
    return _height;
}

void Canvas::clearTo(const Color& c)
{
    std::fill(_pixels.begin(), _pixels.end(), c);
}

Color Canvas::pixel(int w, int h) const
{
    return _pixels.at(h * _width + w);
}

void Canvas::setPixel(int w, int h, Color c)
{
    _pixels.at(h * _width + w) = c;
}
