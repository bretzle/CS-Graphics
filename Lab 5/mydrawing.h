#ifndef MYDRAWING_H
#define MYDRAWING_H

#include "drawbase.h"
#include "shape.h"

// forward reference
class GraphicsContext;

enum draw_state
{
	point = 112,
	line = 108,
	triangle = 116,
	circle = 99,
	rect = 114,
	save = 115,
};

class MyDrawing : public DrawingBase
{
public:
	MyDrawing();
	// we willoverride just these
	virtual void paint(GraphicsContext *gc);
	virtual void keyDown(GraphicsContext *gc, unsigned int keycode);
	virtual void keyUp(GraphicsContext *gc, unsigned int keycode);
	virtual void mouseButtonDown(GraphicsContext *gc, unsigned int button, int x, int y);
	virtual void mouseButtonUp(GraphicsContext *gc, unsigned int button, int x, int y);
	virtual void mouseMove(GraphicsContext *gc, int x, int y);

private:
	// We will only support one "remembered" line
	// In an actual implementation, we would also have one of our "image"
	// objects here to store all of our drawn shapes.
	int x0;
	int y0;
	int x1;
	int y1;
	int x2;
	int y2;
	draw_state state;
	int num_of_points;
	bool done;
	bool dragging; // flag to know if we are dragging
	ShapeTainer box;
};
#endif