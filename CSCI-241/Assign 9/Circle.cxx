#include "Circle.h"

const double pi = 3.14159265358979323846;	//constant to use for pi

/***************************************************************
Circle
Use: constructor for circle objects derived from shape class
Parameters: a string for the color, an integer radius
Returns: nothing
***************************************************************/
Circle::Circle(string newColor, int r2): Shape(newColor)
{
	radius = r2;
}

/***************************************************************
print()
Use: prints out the Circle properties
Parameters: none
Returns: nothing
***************************************************************/
void Circle::print() const 
{
	Shape::print();
		std::cout << " Cricle, radius " << radius << ", area "
		<< getArea() << std::endl;
}

/***************************************************************
getArea()
Use: computes the area of a triangle
Parameters: none
Returns: a double
***************************************************************/
double Circle::getArea() const
{
	return radius * radius * pi;
}