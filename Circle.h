#pragma once

#include "Shape.h"
#include "Point.h"

#define PI 3.14

class Circle : public Shape
{
public:
	Circle(const Point& center, double radius, const std::string& type, const std::string& name);
	~Circle();

	const Point& getCenter() const;
	double getRadius() const;
	
	virtual double getArea() const;
	virtual double getPerimeter() const;
	virtual void move(const Point& other);
	virtual void draw(const Canvas& canvas);
	virtual void clearDraw(const Canvas& canvas);
	// override functions if need (virtual + pure virtual)

protected:
	
	double _radius;
	Point _center;
};