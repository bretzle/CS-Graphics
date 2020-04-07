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
    virtual std::ostream &out(std::ostream &os) const;

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
    ~Line();

    void draw(GraphicsContext *gc);
    std::ostream &out(std::ostream &os) const;
};

/////////////////////////////////////////////////////////////////////

class Triangle : public Shape
{
private:
    matrix p2, p3;

public:
    Triangle(double x0, double y0, double x1, double y1, double x2, double y2, int color);
    ~Triangle();

    void draw(GraphicsContext *gc);
    std::ostream &out(std::ostream &os) const;
};

/////////////////////////////////////////////////////////////////////

class Circle : public Shape
{
private:
    matrix p2;

public:
    Circle(double x0, double y0, double radius, int color);
    ~Circle();

    void draw(GraphicsContext *gc);
    std::ostream &out(std::ostream &os) const;
};

/////////////////////////////////////////////////////////////////////

class Rect : public Shape
{
private:
    matrix p2;

public:
    Rect(double x0, double y0, double x1, double y1, int color);
    ~Rect();

    void draw(GraphicsContext *gc);
    std::ostream &out(std::ostream &os) const;
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
    void draw(GraphicsContext *gc) const;
    std::ostream &out(std::ostream &os) const;
};

/////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &os, const Line &rhs);
std::ostream &operator<<(std::ostream &os, const Triangle &rhs);
std::ostream &operator<<(std::ostream &os, const Circle &rhs);
std::ostream &operator<<(std::ostream &os, const Rect &rhs);
std::ostream &operator<<(std::ostream &os, const ShapeTainer &rhs);

#endif