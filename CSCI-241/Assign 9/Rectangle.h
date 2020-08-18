#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
private:

	int height, width;

public:

	Rectangle(string, int = 0, int = 0);
	void print() const override;
	double getArea() const override;

};

#endif /*RECTANGLE_H*/