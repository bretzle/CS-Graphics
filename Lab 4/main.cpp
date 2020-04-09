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
	GraphicsContext *gc1 = new X11Context(500, 500, GraphicsContext::BLACK);
	GraphicsContext *gc2 = new X11Context(500, 500, GraphicsContext::BLACK);

	ShapeTainer box = ShapeTainer();

	ifstream file;
	file.open("input.txt");
	box.in(file);
	file.close();

	ShapeTainer box2 = ShapeTainer(box);

	cout << box;
	cout << "-----------------" << endl;
	cout << box2;

	box.draw(gc1);
	box.draw(gc2);

	// wait a while
	sleep(5);
	delete gc1;
	delete gc2;

	return 0;
}
