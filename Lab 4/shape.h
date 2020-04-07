#ifndef SHAPE_H
#define SHAPE_H

#include "matrix.h"
#include "gcontext.h"

class Shape
{
protected:
    int color;
    matrix origin;

public:
    Shape(int color);
    Shape(const Shape &from);
    virtual ~Shape();

    virtual void draw(GraphicsContext *gc) = 0;
    virtual std::ostream &out(std::ostream &os) const;

protected:
    Shape &operator=(const Shape &rhs);
};

class Line : public Shape
{
private:
    matrix end;

public:
    Line(double x0, double y0, double x1, double y1, int color);
    ~Line();

    void draw(GraphicsContext *gc);
    std::ostream &out(std::ostream &os) const;
};

#endif