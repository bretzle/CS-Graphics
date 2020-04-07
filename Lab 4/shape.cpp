#include <iomanip>
#include "shape.h"

Shape::Shape(int color) : color(color), origin(4, 1) {}

Shape::Shape(const Shape &from) : color(from.color), origin(from.origin) {}

Shape::~Shape() {}

Shape &Shape::operator=(const Shape &rhs)
{
    if (this != &rhs)
    {
        color = rhs.color;
        origin = matrix(rhs.origin);
    }
    return *this;
}

std::ostream &Shape::out(std::ostream &os) const
{
    os << "\tColor: "
       << "0x"
       << std::uppercase << std::setfill('0') << std::setw(6) << std::hex
       << color << std::endl;

    os << "\tOrigin: ("
       << origin[0][0] << ","
       << origin[1][0] << ","
       << origin[2][0] << ")" << std::endl;

    return os;
}