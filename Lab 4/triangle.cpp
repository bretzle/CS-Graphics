#include <iomanip>
#include "shape.h"

Triangle::Triangle(double x0, double y0, double x1, double y1, double x2, double y2, int color) : Shape(color), p2(4, 1), p3(4, 1)
{
    this->origin[0][0] = x0;
    this->origin[1][0] = y0;
    this->origin[2][0] = 0;
    this->origin[3][0] = 1;

    this->p2[0][0] = x1;
    this->p2[1][0] = y1;
    this->p2[2][0] = 0;
    this->p2[3][0] = 1;

    this->p3[0][0] = x2;
    this->p3[1][0] = y2;
    this->p3[2][0] = 0;
    this->p3[3][0] = 1;
}

Triangle::~Triangle()
{
}

void Triangle::draw(GraphicsContext *gc)
{
    gc->setColor(color);
    gc->drawLine(origin[0][0], origin[1][0], p2[0][0], p2[1][0]);
    gc->drawLine(p2[0][0], p2[1][0], p3[0][0], p3[1][0]);
    gc->drawLine(p3[0][0], p3[1][0], origin[0][0], origin[1][0]);
}

std::ostream &Triangle::out(std::ostream &os) const
{
    os << "Triangle" << std::endl;

    Shape::out(os);

    os << "\tP2: ("
       << p2[0][0]
       << ","
       << p2[1][0]
       << ","
       << p2[2][0]
       << ")" << std::endl;

    os << "\tP3: ("
       << p3[0][0]
       << ","
       << p3[1][0]
       << ","
       << p3[2][0]
       << ")" << std::endl;

    return os;
}