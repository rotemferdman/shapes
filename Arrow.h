#pragma once
#include "Polygon.h"

class Arrow : public Shape
{
public:
	Arrow(const Point& a, const Point& b, const std::string& type, const std::string& name);
	~Arrow();

	virtual void draw(const Canvas& canvas);
	virtual void clearDraw(const Canvas& canvas);
	virtual double getArea() const;
	// override functions if need (virtual + pure virtual)
	virtual double getPerimeter() const;
	virtual void move(const Point& other);
private:
	std::vector<Point> _points;
};