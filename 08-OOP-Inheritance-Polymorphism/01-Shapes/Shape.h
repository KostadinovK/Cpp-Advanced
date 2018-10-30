#pragma once

#include "Vector2D.h"

class Shape {
public:
	Vector2D center;
	double area;

	Shape() : center(0,0), area(0) {}
	Shape(Vector2D center) : center(center), area(0) {}

	virtual Vector2D getCenter() {
		return this->center;
	}

	virtual double getArea() {
		return this->area;
	}

};
