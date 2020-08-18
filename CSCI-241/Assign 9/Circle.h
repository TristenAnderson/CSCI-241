#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
private:

	int radius;

public:

	Circle(string, int = 0);
	void print() const;
	double getArea() const;

};


#endif /*CIRCLE_H*/