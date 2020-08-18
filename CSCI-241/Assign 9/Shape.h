#pragma once

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

using std::string; 

class Shape
{
private:

	std::string Color;

public:

	Shape(const std::string& other);
	virtual ~Shape();
	virtual void print() const;				//virtual
	virtual double getArea() const = 0;		//pure virtual

};

#endif SHAPE_H