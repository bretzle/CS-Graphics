#include "mydrawing.h"
#include "gcontext.h"
#include <iostream>

using namespace std;

// Constructor
MyDrawing::MyDrawing()
{
	dragging = false;
	x0 = x1 = x2 = y0 = y1 = y2 = 0;
	num_of_points = 0;
	color = GraphicsContext::GREEN;
	return;
}

void MyDrawing::paint(GraphicsContext *gc)
{
	// for fun, let's draw a "fixed" shape in the middle of the screen
	// it will only show up after an exposure
	int middlex = gc->getWindowWidth() / 2;
	int middley = gc->getWindowHeight() / 2;
	gc->setColor(GraphicsContext::MAGENTA);
	for (int yi = middley - 50; yi <= middley + 50; yi++)
	{
		gc->drawLine(middlex - 50, yi, middlex + 50, yi);
	}
	gc->setColor(GraphicsContext::GREEN);
	// redraw the line if requested
	gc->drawLine(x0, y0, x1, y1);
	return;
}

void MyDrawing::mouseButtonDown(GraphicsContext *gc, unsigned int button, int x, int y)
{
	// mouse button pushed down
	// -clear context
	// -set origin of new line
	// -set XOR mode for rubber-banding
	// -draw new line in XOR mode.  Note, at this point, the line is
	//   degenerate (0 length), but need to do it for consistency
	// x0 = x1 = x;
	// y0 = y1 = y;
	// gc->setMode(GraphicsContext::MODE_XOR);
	// gc->drawLine(x0, y0, x1, y1);
	// dragging = true;
	switch (state)
	{
	case point:
		gc->setMode(GraphicsContext::MODE_NORMAL);
		gc->drawLine(x, y, x, y);
		break;
	case line:
		x0 = x1 = x;
		y0 = y1 = y;
		gc->setMode(GraphicsContext::MODE_XOR);
		gc->drawLine(x0, y0, x1, y1);
		dragging = true;
		break;
	case triangle:
		if (num_of_points == 0)
		{
			num_of_points = 1;
			x0 = x;
			y0 = y;
			gc->setMode(GraphicsContext::MODE_NORMAL);
			gc->drawLine(x0, y0, x0, y0);
		}
		else if (num_of_points == 1)
		{
			num_of_points = 2;
			x1 = x;
			y1 = y;
			gc->setMode(GraphicsContext::MODE_NORMAL);
			gc->drawLine(x0, y0, x1, y1);
		}
		else
		{
			num_of_points = 3;
			x2 = x;
			y2 = y;
			gc->setMode(GraphicsContext::MODE_XOR);
			gc->drawLine(x0, y0, x2, y2);
			gc->drawLine(x1, y1, x2, y2);
			dragging = true;
		}
		break;
	case circle:
		x0 = x;
		x1 = x;
		y0 = y;
		y1 = y;
		gc->setMode(GraphicsContext::MODE_XOR);
		gc->drawCircle(x0, y0, x1, y1);
		dragging = true;
		break;
	case rect:
		x0 = x;
		y0 = y;
		x1 = x;
		y1 = y;
		gc->setMode(GraphicsContext::MODE_XOR);
		dragging = true;
		break;
	default:
		break;
	}
	return;
}

void MyDrawing::mouseButtonUp(GraphicsContext *gc, unsigned int button, int x, int y)
{
	switch (state)
	{
	case line:
		if (dragging)
		{
			// undraw old line
			gc->drawLine(x0, y0, x1, y1);
			// just in x and y here do not match x and y of last mouse move
			x1 = x;
			y1 = y;
			// go back to COPY mode
			gc->setMode(GraphicsContext::MODE_NORMAL);
			// new line drawn in copy mode
			gc->drawLine(x0, y0, x1, y1);
			// clear flag
			dragging = false;
		}
		break;
	case triangle:
		if (num_of_points == 3 && dragging)
		{
			gc->drawLine(x0, y0, x2, y2);
			gc->drawLine(x1, y1, x2, y2);
			x2 = x;
			y2 = y;
			gc->setMode(GraphicsContext::MODE_NORMAL);
			gc->drawLine(x0, y0, x2, y2);
			gc->drawLine(x1, y1, x2, y2);
			dragging = false;
			num_of_points = 0;
		}
		break;
	case circle:
		if (dragging)
		{
			// undraw old line
			gc->drawCircle(x0, y0, x1, y1);
			// just in x and y here do not match x and y of last mouse move
			x1 = x;
			y1 = y;
			// go back to COPY mode
			gc->setMode(GraphicsContext::MODE_NORMAL);
			// new line drawn in copy mode
			gc->drawCircle(x0, y0, x1, y1);
			// clear flag
			dragging = false;
		}
		break;
	case rect:
		if (dragging)
		{
			gc->drawLine(x0, y0, x0, y1);
			gc->drawLine(x0, y0, x1, y0);
			gc->drawLine(x0, y1, x1, y1);
			gc->drawLine(x1, y0, x1, y1);

			x1 = x;
			y1 = y;
			gc->setMode(GraphicsContext::MODE_NORMAL);

			gc->drawLine(x0, y0, x0, y1);
			gc->drawLine(x0, y0, x1, y0);
			gc->drawLine(x0, y1, x1, y1);
			gc->drawLine(x1, y0, x1, y1);
			dragging = false;
		}
	default:
		break;
	}
	return;
}

void MyDrawing::mouseMove(GraphicsContext *gc, int x, int y)
{
	switch (state)
	{
	case line:
		if (dragging)
		{
			// mouse moved -"undraw" old line, then re-draw in new position
			// will already be in XOR mode if dragging
			// old line undrawn
			gc->drawLine(x0, y0, x1, y1);
			// update
			x1 = x;
			y1 = y;
			// new line drawn
			gc->drawLine(x0, y0, x1, y1);
		}
		break;
	case triangle:
		if (dragging)
		{
			gc->drawLine(x0, y0, x2, y2);
			gc->drawLine(x1, y1, x2, y2);
			x2 = x;
			y2 = y;
			gc->drawLine(x0, y0, x2, y2);
			gc->drawLine(x1, y1, x2, y2);
		}
		break;
	case circle:
		if (dragging)
		{
			gc->drawCircle(x0, y0, x1, y1);
			x1 = x;
			y1 = y;
			gc->drawCircle(x0, y0, x1, y1);
		}
	case rect:
		if (dragging)
		{
			gc->drawLine(x0, y0, x0, y1);
			gc->drawLine(x0, y0, x1, y0);
			gc->drawLine(x0, y1, x1, y1);
			gc->drawLine(x1, y0, x1, y1);
			x1 = x;
			y1 = y;
			gc->drawLine(x0, y0, x0, y1);
			gc->drawLine(x0, y0, x1, y0);
			gc->drawLine(x0, y1, x1, y1);
			gc->drawLine(x1, y0, x1, y1);
		}
	default:
		break;
	}

	return;
}

void MyDrawing::keyDown(GraphicsContext *gc, unsigned int keycode)
{
	switch (keycode)
	{
	case point:
		state = point;
		cout << "POINT" << endl;
		break;
	case line:
		state = line;
		cout << "LINE" << endl;
		break;
	case triangle:
		state = triangle;
		num_of_points = 0;
		cout << "TRIANGLE" << endl;
		break;
	case circle:
		state = circle;
		cout << "CIRCLE" << endl;
		break;
	case rect:
		state = rect;
		temp = new Rect(0, 0, 0, 0, color);
		cout << "RECT" << endl;
		break;
	case save:

		break;

	default:
		cout << "Key down: " << keycode << endl;
		break;
	}
}

void MyDrawing::keyUp(GraphicsContext *gc, unsigned int keycode)
{
	switch (keycode)
	{
	case point:
	case line:
	case triangle:
	case circle:
	case rect:
		break;
	default:
		cout << "Key up: " << keycode << endl;
		break;
	}
}