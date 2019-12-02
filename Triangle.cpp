#include "Triangle.h"
#include <iostream>
#include <math.h>


Triangle::Triangle(const Point& a, const Point& b, const Point& c, const std::string& type, const std::string& name)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->_type = type;
	this->_name = name;

	this->_points.push_back(a);
	this->_points.push_back(b);
	this->_points.push_back(c);

	if (a.getX() == b.getX() == c.getX())
	{
		std::cerr << "All the three points cannot be on the same x";
		_exit(1);
	}
	else if (a.getY() == b.getY() == c.getY())
	{
		std::cerr << "All the three points cannot be on the same y";
		_exit(1);
	}
}

Triangle::~Triangle()
{
}

void Triangle::draw(const Canvas& canvas)
{
	canvas.draw_triangle(_points[0], _points[1], _points[2]);
}

void Triangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_triangle(_points[0], _points[1], _points[2]);
}

double Triangle::getArea() const
{
	//getting the area of the triangle
	double s = (this->a.getX() * (this->c.getY() - this->b.getY()) + this->b.getX() * (this->a.getY() - this->c.getY()) + this->c.getX() * (this->b.getY() - this->a.getY() ));
	
	if (s < 0)
	{
		s = s * -1;
	}
	s = s / 2;
	return s;

}

double Triangle::getPerimeter() const
{
	/*
	getting the perimeter
	*/
	double dis1 = sqrt(((this->_points[1].getX() - this->_points[0].getX()) * (this->_points[1].getX() - this->_points[0].getX())) + ((this->_points[1].getY() - this->_points[0].getY()) * (this->_points[1].getY() - this->_points[0].getY())));
	double dis2 = sqrt(((this->_points[2].getX() - this->_points[1].getX()) * (this->_points[2].getX() - this->_points[1].getX())) + ((this->_points[2].getY() - this->_points[1].getY()) * (this->_points[2].getY() - this->_points[1].getY())));
	double dis3 = sqrt(((this->_points[2].getX() - this->_points[0].getX()) * (this->_points[2].getX() - this->_points[0].getX())) + ((this->_points[2].getY() - this->_points[0].getY()) * (this->_points[2].getY() - this->_points[0].getY())));

	if (dis1 < 0)
	{
		dis1 = dis1 * -1;
	}
	if (dis2 < 0)
	{
		dis2 = dis2 * -1;
	}
	if (dis3 < 0)
	{
		dis3 = dis3 * -1;
	}

	return dis1 + dis2 + dis3;
}

void Triangle::move(const Point& other)
{
	this->_points.pop_back();
	this->_points.push_back(other);
}
