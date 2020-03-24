#include "matrix.h"
#include <string>
#include <cmath>

// Parameterized constructor
matrix::matrix(unsigned int rows, unsigned int cols):rows(rows),cols(cols) 
{  
	if (rows < 1 || cols < 1)
	{
		throw matrixException("p-constructor bad arguments");
	}
	// allocate memory
	the_matrix = new double[rows * cols];
	// clear
	clear();
}

// Copy constructor
matrix::matrix(const matrix& from):rows(from.rows),cols(from.cols)
{
	the_matrix = new double[rows*cols];
	(*this) = from;
}

// Destructor
matrix::~matrix()
{
	delete [] the_matrix;
}

// Assignment operator
matrix& matrix::operator=(const matrix& rhs)
{
	if (this != &rhs)
	{
		if ((rows*cols) != (rhs.rows*rhs.cols))
		{
			delete [] the_matrix;
			the_matrix = new double[rhs.rows * rhs.cols];
		}

		rows = rhs.rows;
		cols = rhs.cols;

		for (int i = 0; i < (rows*cols); i++)
		{
			the_matrix[i] = rhs.the_matrix[i];
		}
	}
	return *this;
}

// Named constructor (static)
matrix matrix::identity(unsigned int size)
{
	// use p-constructor
	return matrix(size,size);
}


// Binary operations
matrix matrix::operator+(const matrix& rhs) const
{
	// stub
	matrix retVal(rhs);
	return retVal;
}


matrix matrix::operator*(const matrix& rhs) const
{
	// stub
	matrix retVal(rhs);
	return retVal;
}

matrix matrix::operator*(const double scale) const
{
	// stub
	matrix retVal(*this);
	return retVal;
}


// Unary operations
matrix matrix::operator~() const
{
	// stub
	matrix retVal(*this);
	return retVal;
}
	

void matrix::clear()
{
	for (int i=0; i<(rows*cols); i++)
	{
		the_matrix[i] = 0.0;
	}
	return;
}

double* matrix::operator[](unsigned int row)
{
	// stub
	return NULL;
}

double* matrix::operator[](unsigned int row) const
{
	// stub
	return NULL;
}


std::ostream& matrix::out(std::ostream& os) const
{
	// stub
	return os;	
}



// Global insertion and operator
std::ostream& operator<<(std::ostream& os, const matrix& rhs)
{
	// stub
	os << "todo";
	return os;
}

// Global scalar multiplication
matrix operator*(const double scale, const matrix& rhs)
{
	// stub
	matrix retval(rhs);
	return retval;
}


