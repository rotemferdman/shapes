#pragma once
#include "Polygon.h"


namespace myShapes
{
	// Calling it MyRectangle becuase Rectangle is taken by global namespace.
	class Rectangle : public Polygon
	{
	public:
		// There's a need only for the top left corner 
		Rectangle(const Point& a, double length, double width, const std::string& type, const std::string& name);
		virtual ~Rectangle();

		// override functions if need (virtual + pure virtual)

		void draw(const Canvas& canvas);

		void clearDraw(const Canvas& canvas);
		virtual double getArea() const;
		virtual double getPerimeter() const;
		virtual void move(const Point& other);
		void set_length(double a);
		void set_width(double b);
		double get_length();

	protected:
		Point a;
		double length;
		double width;
	};
}