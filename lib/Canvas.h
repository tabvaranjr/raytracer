#pragma once

#include <vector>
#include "Color.h"

class Canvas
{
public:
    Canvas(int width, int height);

    int width() const;
    int height() const;

    void clearTo(const Color& c);

    Color pixel(int w, int h) const;
    void setPixel(int w, int h, Color c);

private:
    int _width;
    int _height;
    std::vector<Color> _pixels;
};
