#include <iomanip>
#include "shape.h"

Line::Line(double x0, double y0, double x1, double y1, int color) : Shape(color), end(4, 1)
{
    this->origin[0][0] = x0;
    this->origin[1][0] = y0;
    this->origin[2][0] = 0;
    this->origin[3][0] = 1;

    this->end[0][0] = x1;
    this->end[1][0] = y1;
    this->end[2][0] = 0;
    this->end[3][0] = 1;
}

Line::~Line()
{
}

void Line::draw(GraphicsContext *gc)
{
    gc->setColor(color);
    gc->drawLine(origin[0][0], origin[1][0], end[0][0], end[1][0]);
}

std::ostream &Line::out(std::ostream &os) const
{
    os << "Line" << std::endl;

    Shape::out(os);

    os << "\tEnd: ("
       << end[0][0]
       << ","
       << end[1][0]
       << ","
       << end[2][0]
       << ")" << std::endl;

    return os;
}