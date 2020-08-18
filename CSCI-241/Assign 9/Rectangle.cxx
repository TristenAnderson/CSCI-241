#include "Rectangle.h"

/***************************************************************
Rectangle
Use: constructor for Rectangle object, derived from shape
Parameters: a string, an integer height and integer width
Returns: nothing
***************************************************************/
Rectangle::Rectangle(string newString, int h, int w): Shape(newString)
{
	height = h;
	width = w;
}

/***************************************************************
print()
Use: prints out the shape properties
Parameters: none
Returns: nothing
***************************************************************/
void Rectangle::print() const
{
	Shape::print();
	std::cout << " Rectangle, height " << height << ", width "
		<< width << ", area " << getArea() << std::endl;
}

/***************************************************************
getArea()
Use: computes the area 
Parameters: none
Returns: a double
***************************************************************/
double Rectangle::getArea() const
{
	return double(height)*width;
}