#include "Matrix.h"

/***************************************************************
Matrix
Use: Default constructor, sets matrix to the identity matrix
Parameters: none
Returns: nothing
***************************************************************/
Matrix::Matrix()
{
	for ( int i = 0; i < 2; i++)
	{
		for ( int j = 0; j < 2; j++)
		{
			if ( i == j)
				matrixArray [i][j] = 1;
			else 
				matrixArray [i][j] = 0;
		} 
	}
}

/***************************************************************
Matrix
Use: Alternate constructor, sets matrix to the identity matrix
Parameters: a 2 dimensional integer array (newarr)
Returns: nothing
***************************************************************/
Matrix::Matrix(int newarr[2][2])
{
	for ( int i = 0; i < 2; i++)
	{
		for ( int j = 0; j < 2; j++)
		{
			this->matrixArray [i][j] = newarr [i][j];
		}
	}
}

/***************************************************************
Determinant 
Use: Computes the determinant of a 2 dimensional array array
Parameters: none
Returns: the determinant (an integer value)
***************************************************************/
int Matrix::determinant() const
{
	return (matrixArray[0][0] * matrixArray[1][1]) - (matrixArray[0][1] * matrixArray[1][0]);
	//int det = (matrixArray[0][0]*matrixArray[1][1])-(matrixArray[0][1]*matrixArray[1][0]);
	//return det;
}

/***************************************************************
operator+
Use: computes the sum of two matrixes
Parameters: a reference to constant Matrix object
Returns: a matrix object holding the sum of two matrixes
***************************************************************/
Matrix Matrix::operator+ ( const Matrix& rhs) const
{
	Matrix result; 
	for ( int i = 0; i < 2; i++)
	{
		for ( int j = 0; j < 2; j++)
		{
			result.matrixArray[i][j] = matrixArray[i][j]+rhs.matrixArray[i][j];
		}
	}
	return result;
}

/***************************************************************
operator*
Use: computes the product of scalar multiplication of a matrix and an integer passed in as the right operand 
Parameters: an integer 
Returns: A matrix object holding the scalar product of the matrix array and an integer 
***************************************************************/
Matrix Matrix::operator*( int k ) const
{
	Matrix result;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			result.matrixArray[i][j] = k * matrixArray[i][j];
		}
	}
	return result;
}

/***************************************************************
operator*
Use: Computes the product of two matrix objects 
Parameters: a reference to a constant matrix object
Returns: A matrix object holding the product of two matrix objects 
***************************************************************/
Matrix Matrix::operator*( const Matrix& rhs) const
{
	Matrix result;
	result.matrixArray[0][0] = matrixArray[0][0] * rhs.matrixArray[0][0] + matrixArray[0][1] * rhs.matrixArray[1][0];
	result.matrixArray[0][1] = matrixArray[0][0] * rhs.matrixArray[0][1] + matrixArray[0][1] * rhs.matrixArray[1][1];
	result.matrixArray[1][0] = matrixArray[1][0] * rhs.matrixArray[0][0] + matrixArray[1][1] * rhs.matrixArray[1][0];
	result.matrixArray[1][1] = matrixArray[1][0] * rhs.matrixArray[0][1] + matrixArray[1][1] * rhs.matrixArray[1][1];
	return result;
}

/***************************************************************
operator==
Use: Compares each entry two matrix objects and checks equality
Parameters: a reference to constant matrix object
Returns: a boolean true or false 
***************************************************************/
bool Matrix::operator==( const Matrix& rhs) const
{
	bool equal = true;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (this->matrixArray[i][j] == rhs.matrixArray[i][j])
				equal = true;
			else
				equal = false;
		}
	}
	return equal;
}

/***************************************************************
operator!=
Use: Compares each entry of two matrix objects to check that they are not equal
Parameters: a reference to a constant matrix object
Returns: boolean true or false
***************************************************************/
bool Matrix::operator!=( const Matrix& rhs) const
{
	if (this->matrixArray == rhs.matrixArray)
		return false;
	else
		return true;

}

/***************************************************************
operator<<
Use: overloaded << bitshift to print out a matrix object
Parameters: a reference to an ostream object and a reference to a constant matrix object
Returns: an ostream object
****************************************************************/
ostream& operator<<( ostream& lhs, const Matrix& rhs)
{
	lhs << "[[" << rhs.matrixArray[0][0] << ", " << rhs.matrixArray[0][1] << "], ["
		<< rhs.matrixArray[1][0] << ", " << rhs.matrixArray[1][1] << "]]";

	return lhs;
}

/***************************************************************
operator*
Use: product of an integer as the left operand and a matrix as the right operand 
Parameters: an interger and a reference to a constant matrix object
Returns: A matrix object holding the scalar product of the integer and matrix array
***************************************************************/
Matrix operator*(int k, const Matrix& rhs)
{
	return rhs*k;
}


