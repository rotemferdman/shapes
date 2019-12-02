#include "Point.h"
#include <cmath>
Point::~Point()
{
}

double Point::getX() const
{
	return this->x;
}

double Point::getY() const
{
	return this->y;
}

void Point::setX(double a)
{
	this->x = a;
}

void Point::setY(double b)
{
	this->y = b;
}

double Point::distance(const Point& other) const
{
	double dis = sqrt(((this->x - other.x) * (this->x - other.x)) + ((this->y - other.y) * (this->y - other.y)));
	return dis;
}
