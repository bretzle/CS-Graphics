#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include <iomanip>
#include <unistd.h>
#include <assert.h>

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
	GraphicsContext *gc3 = new X11Context(500, 500, GraphicsContext::BLACK);

	ShapeTainer box = ShapeTainer();

	// create image from file
	ifstream file;
	file.open("input.txt");
	box.in(file);
	file.close();

	// create a copy of the image
	ShapeTainer box2 = ShapeTainer(box);
	// create a copy via assignment
	ShapeTainer box3 = box;

	// print containers to console
	cout << box << endl;
	cout << "------------------------" << endl;
	cout << box2 << endl;
	cout << "------------------------" << endl;
	cout << box3 << endl;

	// check that images are unique
	assert(&box != &box2);
	assert(&box != &box3);
	vector<Shape *> shapes1 = box.get_shapes();
	vector<Shape *> shapes2 = box2.get_shapes();
	vector<Shape *> shapes3 = box3.get_shapes();
	for (unsigned int i = 0; i < shapes1.size(); i++)
	{
		assert(&shapes1[i] != &shapes2[i]);
		assert(&shapes1[i] != &shapes3[i]);
	}

	// display all
	box.draw(gc1);
	box2.draw(gc2);
	box3.draw(gc3);

	// wait a while
	sleep(10);

	// free memory
	delete gc1;
	delete gc2;
	delete gc3;

	return 0;
}
