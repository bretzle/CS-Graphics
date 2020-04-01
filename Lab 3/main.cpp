#include "x11context.h"
#include <unistd.h>
#include <iostream>

int main(void)
{
	GraphicsContext *gc = new X11Context(500, 500, GraphicsContext::BLACK);

	// draw some lines
	gc->setColor(GraphicsContext::GREEN);

	// big square
	gc->drawLine(10, 10, 10, 490);
	gc->drawLine(10, 10, 490, 10);
	gc->drawLine(490, 490, 490, 10);
	gc->drawLine(490, 490, 10, 490);

	for (int i = 10; i <= 490; i += 20)
	{
		gc->drawLine(10, i, 490, 500 - i);
		gc->drawLine(i, 10, 500 - i, 490);
	}

	sleep(5);

	delete gc;

	return 0;
}
