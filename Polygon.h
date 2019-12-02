#pragma once

#include "Shape.h"
#include "Point.h"
#include <vector>

class Polygon : public Shape
{
public:
	//Polygon(const std::string& type, const std::string& name);
	virtual ~Polygon();

	// override functions if need (virtual + pure virtual)

protected:
	std::vector<Point> _points;
};