#include "Rectangle.h"
#include <iostream>
#include "Point.h"


myShapes::Rectangle::Rectangle(const Point& a, double length, double width, const std::string& type, const std::string& name)
{
	/*
	create a rectangle
	*/
	this->a = a;
	this->length = length;
	this->width = width;
	this->_name = name;
	this->_type = type;

	Point b;
	b.setX(a.getX() + length);
	b.setY(a.getY() + width);
	this->_points.push_back(a);
	this->_points.push_back(b);
	if (length <= 0 || width <= 0)
	{
		std::cerr << "width or length cannot be negative";
		_exit(1);
	}
}

myShapes::Rectangle::~Rectangle()
{
}

void myShapes::Rectangle::draw(const Canvas& canvas) //drawing
{
	canvas.draw_rectangle(_points[0], _points[1]);
}

void myShapes::Rectangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_rectangle(_points[0], _points[1]);
}

double myShapes::Rectangle::getArea() const
{
	return this->length * this->width;
}

double myShapes::Rectangle::getPerimeter() const
{
	return this->length*2 + this->width*2;
}

void myShapes::Rectangle::move(const Point& other)
{
	this->a = other;
	this->_points.pop_back();
	this->_points.push_back(other);
}

void myShapes::Rectangle::set_length(double a)
{
	double r = this->_points[0].getX() / a;
	this->length = this->length / r;
}

void myShapes::Rectangle::set_width(double b)
{
	double r = this->_points[0].getY() / b;
	this->width = this->width / r;
}

double myShapes::Rectangle::get_length()
{
	return this->length;
}


