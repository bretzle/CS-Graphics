#include "x11context.h"
#include <unistd.h>
#include <iostream>

int main(void)
{
	GraphicsContext *gc = new X11Context(500, 500, GraphicsContext::BLACK);

	// draw some lines
	gc->setColor(GraphicsContext::GREEN);

	// box
	gc->drawLine(10, 10, 10, 490);
	gc->drawLine(10, 10, 490, 10);
	gc->drawLine(490, 490, 490, 10);
	gc->drawLine(490, 490, 10, 490);
	
	// varius slopes
	for (int i = 10; i <= 490; i += 20)
	{
		gc->drawLine(10, i, 490, 500 - i);
		gc->drawLine(i, 10, 500 - i, 490);
	}

	// draw concentric circles
	gc->setColor(GraphicsContext::RED);
	for (int i = 10; i <= 240; i += 10)
	{
		gc->drawCircle(250, 250, i);
	}

	// wait a while
	sleep(30);
	delete gc;

	return 0;
}
