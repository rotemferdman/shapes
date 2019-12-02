#include "Shape.h"
#include <iostream>


void Shape::printDetails() const
{
	std::cout << _name << " " << _type << std::endl;
}

std::string Shape::getType() const
{

	return this->_type;
}

std::string Shape::getName() const
{
	return this->_name;
}
