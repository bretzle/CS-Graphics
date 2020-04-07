#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include "shape.h"

ShapeTainer::ShapeTainer() {}
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
	{
		if (line.rfind("Line", 0) == 0)
		{
			Line *l = new Line(0, 0, 0, 0, 0);
			l->in(is);
			add(l);
		}
		else if (line.rfind("Triangle", 0) == 0)
		{
			Triangle *t = new Triangle(0, 0, 0, 0, 0, 0, 0);
			t->in(is);
			add(t);
		}
		else if (line.rfind("Circle", 0) == 0)
		{
			Circle *c = new Circle(0, 0, 0, 0);
			c->in(is);
			add(c);
		}
		else if (line.rfind("Rect", 0) == 0)
		{
			Rect *r = new Rect(0, 0, 0, 0, 0);
			r->in(is);
			add(r);
		}
		else
		{
			std::cout << "Unknown line found. Skipping..." << std::endl;
		}
	}

	return is;
}

std::ostream &operator<<(std::ostream &os, const ShapeTainer &rhs)
{
	rhs.out(os);
	return os;
}