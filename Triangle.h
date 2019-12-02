#include "Polygon.h"
#include <string>

class Triangle : public Polygon
{
public:
	Triangle(const Point& a, const Point& b, const Point& c, const std::string& type, const std::string& name);
	virtual ~Triangle();
	
	void draw(const Canvas& canvas);

	void clearDraw(const Canvas& canvas);

	virtual double getArea() const;
	virtual double getPerimeter() const;
	virtual void move(const Point& other);

	// override functions if need (virtual + pure virtual)

protected:
	Point a;
	Point b;
	Point c;
};