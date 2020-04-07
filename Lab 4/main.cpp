#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include <iomanip>

#include "shape.h"
#include "matrix.h"

using namespace std;

/**
 * Main entry point
 */
int main(int argc, char **argv)
{
	cout << "Lab 4" << endl;

	Line s(0, 0, 100, 100);

	s.draw();

	return 0;
}
