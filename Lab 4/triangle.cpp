#include <iomanip>
#include "shape.h"

Triangle::Triangle(double x0, double y0, double x1, double y1, double x2, double y2, int color) : Shape(color), p2(4, 1), p3(4, 1)
{
	this->p1[0][0] = x0;
	this->p1[1][0] = y0;
	this->p1[2][0] = 0;
	this->p1[3][0] = 1;

	this->p2[0][0] = x1;
	this->p2[1][0] = y1;
	this->p2[2][0] = 0;
	this->p2[3][0] = 1;

	this->p3[0][0] = x2;
	this->p3[1][0] = y2;
	this->p3[2][0] = 0;
	this->p3[3][0] = 1;
}

Triangle::Triangle(const Triangle &from) : Shape(from.color), p2(from.p2), p3(from.p3)
{
	p1 = matrix(p1);
}

Triangle::Triangle(std::istream &is) : Shape(color), p2(4, 1), p3(4, 1)
{
	in(is);
}

Triangle::~Triangle()
{
}

void Triangle::draw(GraphicsContext *gc)
{
	gc->setColor(color);
	gc->drawLine(p1[0][0], p1[1][0], p2[0][0], p2[1][0]);
	gc->drawLine(p2[0][0], p2[1][0], p3[0][0], p3[1][0]);
	gc->drawLine(p3[0][0], p3[1][0], p1[0][0], p1[1][0]);
}

std::ostream &Triangle::out(std::ostream &os) const
{
	os << "Triangle" << std::endl;

	Shape::out(os);

	os << "\tP2: ("
	   << p2[0][0]
	   << " "
	   << p2[1][0]
	   << " "
	   << p2[2][0]
	   << ")" << std::endl;

	os << "\tP3: ("
	   << p3[0][0]
	   << " "
	   << p3[1][0]
	   << " "
	   << p3[2][0]
	   << ")" << std::endl;

	return os;
}

std::istream &Triangle::in(std::istream &is)
{
	std::string line, dump;
	char d;
	std::stringstream str_strm;

	Shape::in(is);

	std::getline(is, line);
	str_strm = std::stringstream(line);
	str_strm >> dump;
	str_strm >> d;
	str_strm >> p2[0][0];
	str_strm >> p2[1][0];

	std::getline(is, line);
	str_strm = std::stringstream(line);
	str_strm >> dump;
	str_strm >> d;
	str_strm >> p3[0][0];
	str_strm >> p3[1][0];

	return is;
}

std::ostream &operator<<(std::ostream &os, const Triangle &rhs)
{
	rhs.out(os);
	return os;
}