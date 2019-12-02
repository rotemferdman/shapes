#include "Circle.h"
#include <iostream>


Circle::Circle(const Point& center, double radius, const std::string& type, const std::string& name)
{
	/*
	constractor to circle
	*/
	this->_center = center;
	this->_radius = radius;
	this->_name = name;
	this->_type = type;

	if (radius <= 0) //if the radius is 0
	{
		std::cerr << "radius cannot be negative";
		_exit(1);
	}
}

Circle::~Circle()
{
}

/* g e t t e r s   a n d   s e t t e r s*/
const Point& Circle::getCenter() const
{
	return this->_center;
}

double Circle::getRadius() const
{
	return this->_radius;
}

double Circle::getArea() const
{
	return (PI*_radius)*_radius;
}

double Circle::getPerimeter() const
{
	return 2 * 3.14 * _radius;
}

void Circle::move(const Point& other)
{
	this->_center = other;
}

void Circle::draw(const Canvas& canvas)
{
	canvas.draw_circle(getCenter(), getRadius());
}

void Circle::clearDraw(const Canvas& canvas)
{
	canvas.clear_circle(getCenter(), getRadius());
}



