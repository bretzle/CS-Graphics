#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include <iomanip>
#include <unistd.h>

#include "shape.h"
#include "x11context.h"

using namespace std;

/**
 * Main entry point
 */
int main(int argc, char **argv)
{
	GraphicsContext *gc = new X11Context(500, 500, GraphicsContext::BLACK);

	Line s1 = Line(0, 0, 500, 500, 0xFF0000);
	Line s2 = Line(50, 50, 500, 50, 0xFF0000);
	Triangle t1 = Triangle(50, 450, 450, 450, 250, 50, 0xFF);
	Circle c1 = Circle(250, 250, 100, 0xFF00FF);

	s1.draw(gc);
	s2.draw(gc);
	t1.draw(gc);
	c1.draw(gc);

	cout << s1 << s2 << t1 << c1;

	// wait a while
	sleep(5);
	delete gc;

	return 0;
}
