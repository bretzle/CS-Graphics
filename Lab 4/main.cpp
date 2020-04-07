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

	Line s(0, 0, 500, 500, 0xFF0000);
	Triangle t(50, 450, 450, 450, 250, 50, 0xFF);

	s.draw(gc);
	t.draw(gc);

	cout << s << t;

	// wait a while
	sleep(5);
	delete gc;

	return 0;
}
