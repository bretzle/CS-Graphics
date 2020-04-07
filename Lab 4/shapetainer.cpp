#include "shape.h"

ShapeTainer::ShapeTainer() {}
ShapeTainer::~ShapeTainer() {}

void ShapeTainer::add(Shape *s)
{
	shapes.push_back(s);
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