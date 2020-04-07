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

std::ostream &operator<<(std::ostream &os, const ShapeTainer &rhs)
{
	rhs.out(os);
	return os;
}