#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using std::ostream;

class Matrix
{
	//friend declarations 
	friend ostream& operator<<(ostream& lhs, const Matrix& rhs);
	friend Matrix operator*(int k, const Matrix& rhs);

private:
	//private variables
	int matrixArray[2][2];
	
public:
	//constructors
	Matrix();
	Matrix(int [2][2]);
	
	//arithmetic operators overloaded as methods
	int determinant() const;
	Matrix operator+(const Matrix& rhs) const;
	Matrix operator*(int k) const;
	Matrix operator*(const Matrix& rhs) const;
	
	//relational operators overloaded as methods
	bool operator==(const Matrix& rhs) const;
	bool operator!=(const Matrix& rhs) const;
	
};

#endif /* MATRIX_H */
