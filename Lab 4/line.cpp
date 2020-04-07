#include <iomanip>
#include "shape.h"

Line::Line(double x0, double y0, double x1, double y1, int color) : Shape(color), p2(4, 1)
{
	this->p1[0][0] = x0;
	this->p1[1][0] = y0;
	this->p1[2][0] = 0;
	this->p1[3][0] = 1;

	this->p2[0][0] = x1;
	this->p2[1][0] = y1;
	this->p2[2][0] = 0;
	this->p2[3][0] = 1;
}

Line::~Line()
{
}

void Line::draw(GraphicsContext *gc)
{
	gc->setColor(color);
	gc->drawLine(p1[0][0], p1[1][0], p2[0][0], p2[1][0]);
}

std::ostream &Line::out(std::ostream &os) const
{
	os << "Line" << std::endl;

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

std::ostream &operator<<(std::ostream &os, const Line &rhs)
{
	rhs.out(os);
	return os;
}