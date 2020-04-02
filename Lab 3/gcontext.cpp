/* This is an abstract base class representing a generic graphics
 * context.  Most implementation specifics will need to be provided by
 * a concrete implementation.  See header file for specifics. */

#define _USE_MATH_DEFINES // for M_PI
#include <cmath>		  // for trig functions
#include "gcontext.h"

/*
 * Destructor - does nothing
 */
GraphicsContext::~GraphicsContext()
{
	// nothing to do
	// here to insure subclasses handle destruction properly
}

/* Uses Bresenham's algorithm
 * 
 * Parameters:
 * 	x0, y0 - origin of line
 *  x1, y1 - end of line
 * 
 * Returns: void
 */
void GraphicsContext::drawLine(int x0, int y0, int x1, int y1)
{
	int dx = std::abs(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = -std::abs(y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int err = dx + dy;
	int e2;

	while (true)
	{
		setPixel(x0, y0);

		if (x0 == x1 && y0 == y1)
			break;

		e2 = err << 1;

		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}

		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}

	return;
}

/* Uses the midpoint algorithm
 * 
 * Parameters:
 * 	x0, y0 - origin/center of circle
 *  radius - radius of circle
 * 
 * Returns: void
 */
void GraphicsContext::drawCircle(int x0, int y0, unsigned int radius)
{
	int p = 1 - radius;
	int ddF_x = 0;
	int ddF_y = -2 * radius;
	int x = 0;
	int y = radius;

	// edges
	setPixel(x0, y0 + radius);
	setPixel(x0, y0 - radius);
	setPixel(x0 + radius, y0);
	setPixel(x0 - radius, y0);

	while (x < y)
	{
		// outside the circle circle
		if (p >= 0)
		{
			--y;
			ddF_y += 2;
			p += ddF_y;
		}
		
		++x;
		ddF_x += 2;
		p += ddF_x + 1;

		// the octants
		setPixel(x0 + x, y0 - y); // 1
		setPixel(x0 + y, y0 - x); // 2
		setPixel(x0 + y, y0 + x); // 3
		setPixel(x0 + x, y0 + y); // 4
		setPixel(x0 - x, y0 + y); // 5
		setPixel(x0 - y, y0 + x); // 6
		setPixel(x0 - y, y0 - x); // 7
		setPixel(x0 - x, y0 - y); // 8
	}

	return;
}

void GraphicsContext::endLoop()
{
	run = false;
}
