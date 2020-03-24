#include "matrix.h"
#include <iostream>

using namespace std;

matrix create123();
matrix fill(double);

int main(void)
{
	// test constructor
	matrix m1(3, 3);
	cout << "m1 - should be all zeros" << endl;
	cout << m1 << endl;

	// test identity
	matrix m2 = matrix::identity(5);
	cout << "m2 - should be 5 x 5 identity matrix" << endl;
	cout << m2 << endl;

	// test + operator
	matrix m3 = m2 + m2;
	cout << "m3 = m2 + m2" << endl;
	cout << m3 << endl;

	// test [] operator
	matrix m4 = create123();
	cout << "m4 = 123 matrix" << endl;
	cout << m4 << endl;

	// test multiply: 2.0 * matrix
	matrix m5 = matrix::identity(3);
	m5 = 2.0 * m5;
	cout << "m5 = (2.0 * identity)" << endl;
	cout << m5 << endl;

	// test multiply: matrix * 2.0
	matrix m6 = matrix::identity(3);
	m6 = m6 * 2.0;
	cout << "m6 = (identity * 2.0)" << endl;
	cout << m6 << endl;

	// test transpose
	matrix m7 = ~create123();
	cout << "m7 = Transpose of 123matrix" << endl;
	cout << m7 << endl;

	// test multiply: matix * matrix
	matrix m8 = fill(1) * fill(1);
	cout << "m8 = 1matrix * 1matrix = 3matrix" << endl;
	cout << m8 << endl;

	// test assignment
	matrix m9 = matrix::identity(3);
	matrix m10 = matrix(3, 3);
	cout << "Test assignment" << endl;
	cout << "m9" << endl;
	cout << m9 << endl;
	cout << "m10" << endl;
	cout << m10 << endl;
	cout << "Assign m9 = m10" << endl;
	m9 = m10;
	cout << "m9" << endl;
	cout << m9 << endl;
	cout << "m10" << endl;
	cout << m10 << endl;

	// test [] operator
	m9[1][1] = 1.0;
	cout << "Assure they point to different memory locations" << endl;
	cout << "m9" << endl;
	cout << m9 << endl;
	cout << "m10" << endl;
	cout << m10 << endl;

	return 0;
}

matrix create123()
{
	matrix m(3, 3);

	int val = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m[i][j] = val;
			val++;
		}
	}

	return m;
}

matrix fill(double val)
{
	matrix m(3, 3);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m[i][j] = val;
		}
	}

	return m;
}