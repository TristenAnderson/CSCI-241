#pragma once
#ifndef VECTORN_H
#define VECTORN_H

#include <ostream>
#include <stdlib.h>
using std::ostream;
using std::size_t;

class VectorN
{
	//friend functions 
	friend ostream& operator<<(ostream& lhs, const VectorN& rhs);
	friend VectorN operator*(double lhs, const VectorN& rhs);

private:

	//private variables, a pointer to a double and an unsigned integer 
	unsigned int capacity;
	double * ptr;

public:

	VectorN();											//default constructor
	VectorN(const double values[], size_t n);			//alternate constructor
	VectorN(const VectorN& other);						//copy constructor
	~VectorN();											//destructor 

	//methods and overloaded operators
	void clear();
	VectorN& operator = (const VectorN& other); 
	size_t size() const;
	VectorN operator + (const VectorN& other) const;
	VectorN operator - (const VectorN& other) const;
	VectorN operator * (double rhs) const;
	double operator * (const VectorN& other) const;
	bool operator==(const VectorN& lhs) const;
	double operator[](int sub) const;
	double& operator[](int sub);
	double at(int sub) const;							//subrscipt operators with exception handling read only and read write
	double& at(int sub);

};

#endif /*VECTOR_H*/