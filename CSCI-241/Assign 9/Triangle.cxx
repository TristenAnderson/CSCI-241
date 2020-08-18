#include "Triangle.h"

/***************************************************************
Triangle
Use: constructor for Triangle object derived from shape
Parameters: a string for the color, an integer height and integer base
Returns: nothing
***************************************************************/
Triangle::Triangle(string newString, int h, int b): Shape(newString)
{
	height = h;
	base = b; 
}

/***************************************************************
print()
Use: prints out the Triangle properties
Parameters: none
Returns: nothing
***************************************************************/
void Triangle::print() const
{
	Shape::print();
	std::cout << " Triangle, height " << height << ", base "
		<< base << ", area " << getArea() << std::endl;
}

/***************************************************************
getArea
Use: computes the area of the triangle
Parameters: none
Returns: a double
***************************************************************/
double Triangle::getArea() const
{
	return (0.5*height*base);
}

