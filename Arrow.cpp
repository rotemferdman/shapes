#include "Arrow.h"
#include <iostream>

Arrow::Arrow(const Point& a, const Point& b, const std::string& type, const std::string& name)
{
	/*
	arrow constractor function
	*/
	this->_points.push_back(a);
	this->_points.push_back(b);
	this->_name = name;
	this->_type = type;
}

Arrow::~Arrow()
{
}

void Arrow::draw(const Canvas& canvas)
{
	canvas.draw_arrow(_points[0], _points[1]);
}
void Arrow::clearDraw(const Canvas& canvas)
{
	canvas.clear_arrow(_points[0], _points[1]);
}

double Arrow::getArea() const
{
	return 0.0;
}

double Arrow::getPerimeter() const
{
	double dis = sqrt(((this->_points[1].getX() - this->_points[0].getX()) * (this->_points[1].getX() - this->_points[0].getX())) + ((this->_points[1].getY() - this->_points[0].getY()) * (this->_points[1].getY() - this->_points[0].getY())));

	if (dis < 0) //if negative
	{
		dis = dis * -1;
	}
	return dis;
}

void Arrow::move(const Point& other)
{
	this->_points.pop_back();
	this->_points.push_back(other);
}





