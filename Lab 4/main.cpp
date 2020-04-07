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

	ifstream file;
	file.open("input.txt");
	box.in(file);
	file.close();

	box.draw(gc);

	cout << box;

	// wait a while
	sleep(5);
	delete gc;

	return 0;
}
