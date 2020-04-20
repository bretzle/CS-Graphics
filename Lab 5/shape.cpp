#include <iomanip>
#include "shape.h"

Shape::Shape(int color) : color(color), p1(4, 1) {}

Shape::Shape(const Shape &from) : color(from.color), p1(from.p1) {}

Shape::~Shape() {}

Shape &Shape::operator=(const Shape &rhs)
{
	if (this != &rhs)
	{
		color = rhs.color;
		p1 = matrix(rhs.p1);
	}
	return *this;
}

std::ostream &Shape::out(std::ostream &os) const
{
	os << "\tColor: "
	   << "0x"
	   << std::uppercase << std::setfill('0') << std::setw(6) << std::hex
	   << color << std::endl;

	os << "\tP1: ("
	   << p1[0][0] << " "
	   << p1[1][0] << " "
	   << p1[2][0] << ")" << std::endl;

	return os;
}

std::istream &Shape::in(std::istream &is)
{
	std::string line, dump;
	std::stringstream str_strm;
	char d;

	std::getline(is, line);
	str_strm = std::stringstream(line);
	str_strm >> dump;
	str_strm >> std::hex >> color;

	std::getline(is, line);
	str_strm = std::stringstream(line);
	str_strm >> dump;
	str_strm >> d;
	str_strm >> p1[0][0];
	str_strm >> p1[1][0];

	return is;
}