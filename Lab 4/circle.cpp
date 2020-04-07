#include <iomanip>
#include "shape.h"

Circle::Circle(double x0, double y0, double radius, int color) : Shape(color), p2(4, 1)
{
    this->p1[0][0] = x0;
    this->p1[1][0] = y0;
    this->p1[2][0] = 0;
    this->p1[3][0] = 1;

    this->p2[0][0] = x0 + radius;
    this->p2[1][0] = y0;
    this->p2[2][0] = 0;
    this->p2[3][0] = 1;
}

Circle::~Circle()
{
}

void Circle::draw(GraphicsContext *gc)
{
    gc->setColor(color);
    gc->drawCircle(p1[0][0], p1[1][0], p2[0][0] - p1[0][0]);
}

std::ostream &Circle::out(std::ostream &os) const
{
    os << "Circle" << std::endl;

    Shape::out(os);

    os << "\tP2: ("
       << p2[0][0]
       << ","
       << p2[1][0]
       << ","
       << p2[2][0]
       << ")" << std::endl;

    return os;
}

std::ostream &operator<<(std::ostream &os, const Circle &rhs)
{
    rhs.out(os);
    return os;
}