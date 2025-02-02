#include "Point.hpp"

#include <iostream>

using	std::cout;
using	std::endl;

Point::Point(): x(0), y(0) {}

Point::Point(const float x, const float y): x(x), y(y) {}

Point::Point(const Point &point)
{
	*this = point;
}

Point &Point::operator = (const Point &point)
{
	if (this == &point)
		return (*this);
	this->x = point.getX();
	this->y = point.getY();
	return (*this);
}

Point::~Point() {}

Fixed const	&Point::getX() const
{
	return (x);
}

Fixed const &Point::getY() const
{
	return (y);
}

ostream &operator << (ostream &outs, const Point &point)
{
	outs << "(";
	outs << point.getX().toFloat();
	outs << ", ";
	outs << point.getY().toFloat();
	outs << ")";
	return (outs);
}