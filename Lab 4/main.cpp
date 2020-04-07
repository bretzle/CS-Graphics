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

	ShapeTainer box = ShapeTainer();

	box.add(new Line(0, 0, 500, 500, 0xFF0000));
	box.add(new Line(50, 50, 500, 50, 0xFF0000));
	box.add(new Triangle(50, 450, 450, 450, 250, 50, 0xFF));
	box.add(new Circle(250, 250, 100, 0xFF00FF));
	box.add(new Rect(25, 25, 475, 475, 0xFFFF00));

	box.draw(gc);

	cout << box;

	// wait a while
	sleep(5);
	delete gc;

	return 0;
}
