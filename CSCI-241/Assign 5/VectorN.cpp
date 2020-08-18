
#include "VectorN.h"
#include <iostream>

using std::cout;
using std::endl;
using std::out_of_range;

/***************************************************************
VectorN (default constructor)
Use: initialize capacity to zero and ptr to nullptr
Parameters: none
Returns: nothing
***************************************************************/
VectorN::VectorN()
{
	capacity = 0;
	ptr = nullptr;
}

/***************************************************************
VectorN (alternate constructor)
Use: initialize capacity to n and copy array of values to ptr after dynamically allocating
memory for ptr.
Parameters: a constant array of doubles, and an unsigned int
Returns: nothing
***************************************************************/
VectorN::VectorN(const double values[], size_t n)
{
	capacity = n;
	if (capacity == 0)
		ptr = nullptr;
	else
	{	
		ptr = new double[n];
		for (size_t i = 0; i < capacity; i++)
		{
			ptr[i] = values[i];
		}
	}
}

/***************************************************************
VectorN (the copy constructor)
Use: Copy a vectorN object into a new one 
Parameters: a reference to a constant vertorN object
Returns: nothing
***************************************************************/
VectorN::VectorN(const VectorN& other)						
{
	capacity = other.capacity;
	if (capacity == 0)
		ptr = nullptr;
	else
	{
		ptr = new double [capacity];
		for (size_t i = 0; i < capacity; i++)
			ptr[i] = other.ptr[i];
	}
}
/***************************************************************
~VectorN (destructor)
Use: clears the vectorN object i.e. set capacity to zero and ptr to nullptr after deleting dynamic memory 
Parameters: none
Returns: nothing
***************************************************************/
VectorN::~VectorN()
{
	clear();
}

/***************************************************************
clear()
Use: initialize capacity to n and copy array of values to ptr after dynamically allocating
memory for ptr.
Parameters: none
Returns: nothing
***************************************************************/
void VectorN::clear()
{
	capacity = 0;											//set capacity to zero, delete dynamic memory for vector and set ptr to nullptr
	delete [] ptr;
	ptr = nullptr;
}

/***************************************************************
operator = 
Use: Overloads the = operator to equate to vectorN objects
Parameters: a reference to a constant vectorN object
Returns: a reference to VectorN object
***************************************************************/
VectorN& VectorN::operator = (const VectorN& other)
{
	if (ptr == other.ptr)									//if they are already equal return *this
		return *this;
	else
	{ 
		delete [] this->ptr;								//clear the array of the calling vector
		capacity = other.capacity;							//capacity of calling vector = capacity of other
		if (capacity == 0)									//if the capacity = 0, set to nullptr
			ptr = nullptr;
		else
		{
			ptr = new double[capacity];						//create new dynamic memory allocation and copy the contents of other to this->ptr[]
			for (size_t i = 0; i < capacity; i++)
				ptr[i] = other.ptr[i];
		}
		return *this;										//return a reference to this
	}
}

/***************************************************************
size()
Use: Returns the capacity of the vector
Parameters: none
Returns: an unsigned int
***************************************************************/
size_t VectorN::size() const
{
	return capacity;										//return the capacity/size
}

/***************************************************************
operator + 
Use: adds two VectorN objects together
Parameters: a reference to a constant VectorN object
Returns: A VectorN object
***************************************************************/
VectorN VectorN::operator + (const VectorN& other) const 
{
	VectorN result;											//create a result placeholder

	if (capacity < other.capacity)							//find the vector with less elements and set cacpactity to that
		result.capacity = capacity;
	else
		result.capacity = other.capacity;

	result.ptr = new double[result.capacity];				//allocate dynamic memory to result vector

	for (size_t i = 0; i < result.capacity; i++)			//copy the sum of this and other to the result vector
		result[i] = this->ptr[i] + other.ptr[i];

	return result;											//return the result vectorN object
}

/***************************************************************
operator - 
Use: Find the difference between two vectorN objects 
Parameters: a reference to a constant VectorN object
Returns: a vectorN object
***************************************************************/
VectorN VectorN::operator - (const VectorN& other) const
{
	VectorN result;											//the logic here is the same as the + operator

	if (capacity < other.capacity)
		result.capacity = capacity;
	else
		result.capacity = other.capacity;

	result.ptr = new double[result.capacity];

	for (size_t i = 0; i < result.capacity; i++)
		result[i] = this->ptr[i] - other.ptr[i];

	return result;
}

/***************************************************************
operator * (scalar/dot product)
Use: Find the dot product of two vectors
Parameters: a reference to a constant VectorN object
Returns: a double holding the value of the scalar product
***************************************************************/
double VectorN::operator * (const VectorN& other) const
{
	double product = 0;										//initial local variables for placeholdign and math
	VectorN result;

	if (capacity < other.capacity)							//find the lesser of two capacities
		result.capacity = capacity;
	else
		result.capacity = other.capacity;

	result.ptr = new double[result.capacity];				//allocate memory dynamically from the heap

	for (size_t i = 0; i < result.capacity; i++)			//calculate the result vector
		result[i] = this->ptr[i] * other.ptr[i];

	for (size_t j = 0; j < result.capacity; j++)			//find the dot product
		product += result[j];

	return product;
}

/***************************************************************
VectorN (alternate constructor)
Use: overloads the bitshift operator such that we can "cout <<" vectorN objects
Parameters: lhs a reference to an ostream object and rhs a reference to constant vectorN object
Returns: an ostream object
***************************************************************/
ostream& operator<<(ostream& lhs, const VectorN& rhs)
{
	lhs << '(';
	for (size_t i = 0; i < rhs.capacity; i++)
	{
		if (i == (rhs.capacity - 1))
			lhs << rhs.ptr[i];
		else
			lhs << rhs.ptr[i] << ", ";
	}
	lhs << ')';
	return lhs;
}

/***************************************************************
operator == 
Use: Compare two vectorN objects element by element to check equality
Parameters: a reference to a constant vectorN object
Returns: boolean true false logic
***************************************************************/
bool VectorN::operator==(const VectorN& lhs) const
{
	bool equal = true;
	if (capacity != lhs.capacity)								//check capacity first becuase if not same size then not equal
		return false;
	for (unsigned int i = 0; i < capacity; i++)					//next check each element for equality
	{
		if (ptr[i] == lhs.ptr[i])
			equal = true;
		else
		{
			return false;
		}
	}
	return equal;
}

/***************************************************************
operator [] (read only)
Use: Overloads the [] subscript operator so that we can pull elements of vector objects
Parameters: an integer holding the value of the subscript
Returns: a double
***************************************************************/
double VectorN::operator[](int sub) const
{
	if (sub >= 0 && sub < capacity)
		return ptr[sub];
}

/***************************************************************
operator * (vector multiplication)
Use: Muliplies a vectorN object by another VectorN to get their product
Parameters: a double and a reference to a constant vectorN object 
Returns: a vectorN object
***************************************************************/
VectorN operator*(double lhs, const VectorN& rhs)
{
	VectorN result;
	result.capacity = rhs.capacity;
	result.ptr = new double[rhs.capacity];

	for (size_t i = 0; i < result.capacity; i++)
		result[i] = rhs.ptr[i] * lhs;
	return result;
}

/***************************************************************
operator * (scalar multiplication)
Use: Muliplies a vectorN object by a scalar product to form a new VectorN object
Parameters: a double 
Returns: a vectorN object
***************************************************************/
VectorN VectorN::operator*(double rhs) const
{
	VectorN result;
	result.capacity = capacity;
	result.ptr = new double[capacity];

	for (unsigned int i = 0; i < capacity; i++)
		result.ptr[i] = this->ptr[i] * rhs;
	return result;
}

/***************************************************************
operator [] (read-write version)
Use: returns the values of the VectorN object at the subscript passed in
Parameters: an integer
Returns: a reference to a double
***************************************************************/
double& VectorN::operator[](int sub)
{
	return ptr[sub];
}

/***************************************************************
at (read only)
Use: Same as the subscript operator however this uses exception handling
Parameters: an integer
Returns: a double
***************************************************************/
double VectorN::at(int sub) const
{
	if (sub >= 0 && sub < capacity)
		return this->ptr[sub];
	else
	{
		out_of_range ptr("subscript out of range");
		throw ptr;
	}
}

/***************************************************************
at (read-write)
Use: same as subscript operator but uses exception handling
Parameters: an integer
Returns: a reference to a double
***************************************************************/
double& VectorN::at(int sub) 
{
	if (sub >= 0 && sub < capacity)								//if the subscript is valid (i.e. greater than zero and less than capacity) keep it
		return this->ptr[sub];
	else
	{
		out_of_range ptr("subscript out of range");				//else its out of range and catch it 
		throw ptr;
	}
}
