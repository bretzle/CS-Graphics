#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include "matrix.h"
#include "gcontext.h"

/////////////////////////////////////////////////////////////////////

class Shape
{
protected:
	int color;
	matrix p1;

public:
	Shape(int color);
	Shape(const Shape &from);
	virtual ~Shape();

	virtual void draw(GraphicsContext *gc) = 0;
	virtual Shape *clone() = 0;
	virtual std::ostream &out(std::ostream &os) const;
	virtual std::istream &in(std::istream &is);

protected:
	Shape &operator=(const Shape &rhs);
};

/////////////////////////////////////////////////////////////////////

class Line : public Shape
{
private:
	matrix p2;

public:
	Line(double x0, double y0, double x1, double y1, int color);
	Line(const Line &from);
	Line(std::istream &is);
	~Line();

	void draw(GraphicsContext *gc);
	Shape *clone();
	std::ostream &out(std::ostream &os) const;
	std::istream &in(std::istream &is);
};

/////////////////////////////////////////////////////////////////////

class Triangle : public Shape
{
private:
	matrix p2, p3;

public:
	Triangle(double x0, double y0, double x1, double y1, double x2, double y2, int color);
	Triangle(const Triangle &from);
	Triangle(std::istream &is);
	~Triangle();

	void draw(GraphicsContext *gc);
	Shape *clone();
	std::ostream &out(std::ostream &os) const;
	std::istream &in(std::istream &is);
};

/////////////////////////////////////////////////////////////////////

class Circle : public Shape
{
private:
	matrix p2;

public:
	Circle(double x0, double y0, double radius, int color);
	Circle(const Circle &from);
	Circle(std::istream &is);
	~Circle();

	void draw(GraphicsContext *gc);
	Shape *clone();
	std::ostream &out(std::ostream &os) const;
	std::istream &in(std::istream &is);
};

/////////////////////////////////////////////////////////////////////

class Rect : public Shape
{
private:
	matrix p2;

public:
	Rect(double x0, double y0, double x1, double y1, int color);
	Rect(const Rect &from);
	Rect(std::istream &is);
	~Rect();

	void draw(GraphicsContext *gc);
	Shape *clone();
	std::ostream &out(std::ostream &os) const;
	std::istream &in(std::istream &is);
};

/////////////////////////////////////////////////////////////////////

class ShapeTainer
{
private:
	std::vector<Shape *> shapes;

public:
	ShapeTainer();
	ShapeTainer(const ShapeTainer &from);
	~ShapeTainer();

	ShapeTainer &operator=(const ShapeTainer &rhs);

	void add(Shape *s);
	void erase();
	void draw(GraphicsContext *gc) const;
	std::ostream &out(std::ostream &os) const;
	std::istream &in(std::istream &is);
};

/////////////////////////////////////////////////////////////////////

// print statements
std::ostream &operator<<(std::ostream &os, const Line &rhs);
std::ostream &operator<<(std::ostream &os, const Triangle &rhs);
std::ostream &operator<<(std::ostream &os, const Circle &rhs);
std::ostream &operator<<(std::ostream &os, const Rect &rhs);
std::ostream &operator<<(std::ostream &os, const ShapeTainer &rhs);

#endif