/***********************************************************
CSCI 241 - Assignment 9

Progammer: Tristen Anderson
Z-ID: z1820036

Purpose: Shows inheritance and polymorphism using a base shape class
with derived triangles, circles... uses vitural methods and overrides
************************************************************/

#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <iostream>
#include <vector>
#include <string>

//function declarations
void printVector(std::vector <Shape *> shapes);
void Clear(std::vector <Shape *> shapes);
void printCir(std::vector <Shape *> shapes);

int main()
{
	std::vector <Shape *> shapes(6);

	shapes[0] = new Circle("green", 10);
	shapes[1] = new Rectangle("red", 8, 6);
	shapes[2] = new Triangle("yellow", 8, 4);
	shapes[3] = new Triangle("black", 4, 10);
	shapes[4] = new Circle("orange", 5);
	shapes[5] = new Rectangle("blue", 3, 7);

	//print all shapes
	printVector(shapes);

	std::cout << std::endl << "Printing Circles..." << std::endl << std::endl;

	//print only the circles to show downcasting
	printCir(shapes);

	//free up the memory for good practice
	Clear(shapes);

	return 0;
}

/***************************************************************
printVector
Use: prints out all shapes
Parameters: 1. a vector shapes
Returns: nothing
***************************************************************/
void printVector(std::vector <Shape *> shapes)
{
	for (unsigned int i = 0; i < shapes.size(); i++)
		shapes[i]->print();
}

/***************************************************************
printCir
Use: prints only the circles by downcasting
Parameters: 1. a vector of shapes
Returns: nothing
***************************************************************/
void printCir(std::vector <Shape *> shapes)
{
	for (unsigned int i = 0; i < shapes.size(); i++)
	{
		//downcast to circles
		Circle* cirPtr = dynamic_cast<Circle *> (shapes[i]);
		if (cirPtr != nullptr)
			cirPtr->print();
	}
}

/***************************************************************
Clear
Use: clears up dynamic memory
Parameters: 1. a vector of shapes
Returns: nothing
***************************************************************/
void Clear(std::vector <Shape *> shapes)
{
	for (unsigned int i = 0; i < shapes.size(); i++)
		delete shapes[i];
}

/*		SAMPLE OUTPUT
green circle, radius 10, area 314.159
red rectangle, height 8, width 6, area 48
yellow triangle, height 8, base 4, area 16
black triangle, height 4, base 10, area 20
orange circle, radius 5, area 78.5397
blue rectangle, height 3, width 7, area 21

Printing only circles...

green circle, radius 10, area 314.159
orange circle, radius 5, area 78.5397
*/