#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>

#include "shape.h"
#include "matrix.h"

using namespace std;

/**
 * Main entry point
 */
int main(int argc, char **argv)
{
	cout << "Lab 4" << endl;

	Line s(0, 0, 100, 100);

	s.draw();

	return 0;
}

Shape::Shape() : color(0), origin(4, 1)
{
}

Shape::~Shape()
{
}

Line::Line(double x0, double y0, double x1, double y1) : Shape(), end(4, 1)
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

void Line::draw()
{
	cout << "Line{ start: ("
		 << this->origin[0][0]
		 << ","
		 << this->origin[1][0]
		 << "), end: ("
		 << this->end[0][0]
		 << ","
		 << this->end[1][0]
		 << ") }"
		 << endl;
}