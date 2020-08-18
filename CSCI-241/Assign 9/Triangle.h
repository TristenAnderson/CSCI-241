#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape				//Triangle is a derived class from Shape
{
private:

	int height, base;

public:

	Triangle(string, int = 0, int = 0);		//Triangle constructor
	void print() const override;			//overidden print method
	double getArea() const override;		//overidden getArea method

};

#endif /*TRIANGLE_H*/