#ifndef SHAPE_H
#define SHAPE_H

#include "matrix.h"

class Shape
{
protected:
    int color;
    matrix origin;

public:
    Shape();
    virtual ~Shape();

    virtual void draw() = 0;
};

class Line : public Shape
{
private:
    matrix end;

public:
    Line(double x0, double y0, double x1, double y1);
    ~Line();

    void draw();
};

#endif