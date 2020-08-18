#include "Shape.h"

/***************************************************************
Shape
Use: constructor, sets color to other
Parameters: 1. a reference to a string that is constant 
Returns: nothing
***************************************************************/
Shape::Shape(const string& other)
{
	this->Color = other;
}

/***************************************************************
~Shape
Use: avoid complier warnings
Parameters: none
Returns: nothing
***************************************************************/
Shape::~Shape()
{
	//no content needed
}

/***************************************************************
print()
Use: prints out the color of the shape object
Parameters: none
Returns: nothing
***************************************************************/
void Shape::print() const
{
	std::cout << Color;
}


