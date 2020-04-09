#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include "shape.h"

ShapeTainer::ShapeTainer() {}

ShapeTainer::ShapeTainer(const ShapeTainer &from)
{
	for (auto i = from.shapes.cbegin(); i != from.shapes.cend(); ++i)
	{
		add((*i)->clone());
	}
}

ShapeTainer::~ShapeTainer()
{
	erase();
}

void ShapeTainer::add(Shape *s)
{
	shapes.push_back(s);
}

void ShapeTainer::erase()
{
	for (auto i = shapes.cbegin(); i != shapes.cend(); ++i)
		delete (*i);
}

void ShapeTainer::draw(GraphicsContext *gc) const
{
	for (auto i = shapes.cbegin(); i != shapes.cend(); ++i)
		(*i)->draw(gc);
}

std::ostream &ShapeTainer::out(std::ostream &os) const
{
	for (auto i = shapes.cbegin(); i != shapes.cend(); ++i)
		(*i)->out(os);
	return os;
}

std::istream &ShapeTainer::in(std::istream &is)
{
	std::string line;

	while (std::getline(is, line))
		if (line.rfind("Line", 0) == 0)
			add(new Line(is));
		else if (line.rfind("Triangle", 0) == 0)
			add(new Triangle(is));
		else if (line.rfind("Circle", 0) == 0)
			add(new Circle(is));
		else if (line.rfind("Rect", 0) == 0)
			add(new Rect(is));
		else
			std::cout << "Unknown line found. Skipping..." << std::endl;

	return is;
}

std::ostream &operator<<(std::ostream &os, const ShapeTainer &rhs)
{
	rhs.out(os);
	return os;
}