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

	s.draw(gc);

	// wait a while
	sleep(5);
	delete gc;

	return 0;
}
