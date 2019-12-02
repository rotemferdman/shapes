#pragma once

class Point
{
public:
	//Point(double x, double y);
	//Point(const Point& other);
	virtual ~Point();
	
	Point operator+(const Point& other) const;
	Point& operator+=(const Point& other);

	double getX() const;
	double getY() const;

	void setX(double a);
	void setY(double b);

	double distance(const Point& other) const;

protected:
	double x;
	double y;
};