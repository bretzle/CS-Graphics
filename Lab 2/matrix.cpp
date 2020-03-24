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
	matrix ret(size, size);

	for (int i = 0; i < size; i++)
	{
		ret[i][i] = 1.0;
	}

	return ret;
}


// Binary operations
matrix matrix::operator+(const matrix& rhs) const
{
	if (rows!=rhs.rows || cols!=rhs.cols)
	{
		throw matrixException("Operator+ size mismatch");
	}
	
	matrix retVal(rows, cols);

	for (int i = 0; i < (rows*cols); i++)
	{
		retVal.the_matrix[i] = the_matrix[i] + rhs.the_matrix[i];
	}

	return retVal;
}


matrix matrix::operator*(const matrix& rhs) const
{
	if (cols != rhs.rows)
	{
		throw matrixException("Operator+ size mismatch");
	}
	
	matrix retVal(rows, rhs.cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rhs.cols; j++)
		{
			the_matrix[i*rhs.cols + j] = 0.0; // todo
		}
		
	}
	

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
	matrix retVal(*this);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			retVal.the_matrix[i*rows+j] = the_matrix[j*rows+i];
		}
	}

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
	double* ret = the_matrix;

	ret += row*cols;

	return ret;
}

double* matrix::operator[](unsigned int row) const
{
	double* ret = the_matrix;

	ret += row*cols;

	return ret;
}


std::ostream& matrix::out(std::ostream& os) const
{
	os << "[[ ";
	for (int z = 0; z < cols; z++)
	{
		os << the_matrix[z] << " ";
	}
	
	os << "]" << std::endl;

	for (int i = 1; i < rows - 1; i++)
	{
		os << " [ ";
		for (int z = 0; z < cols; z++)
	{
		os << the_matrix[i*rows + z] << " ";
	}
		os << "]" << std::endl;
	}

	os << " [ ";
	for (int z = 0; z < cols; z++)
	{
		os << the_matrix[(rows-1)*rows + z] << " ";
	}
	os << "]]";

	return os;
}



// Global insertion and operator
std::ostream& operator<<(std::ostream& os, const matrix& rhs)
{
	rhs.out(os);
	return os;
}

// Global scalar multiplication
matrix operator*(const double scale, const matrix& rhs)
{
	// stub
	matrix retval(rhs);
	return retval;
}


