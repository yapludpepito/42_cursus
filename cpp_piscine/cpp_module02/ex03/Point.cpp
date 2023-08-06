#include "Point.hpp"

Point::Point():x(0), y(0) {}

Point::Point(float x, float y): x(x), y(y) {}

Point::Point(const Point &p): x(p.x), y(p.y) {}

Point &Point::operator=(const Point &p)
{
	if (this != &p)
	{
		(Fixed)this->x = p.get_x();
		(Fixed)this->y = p.get_y();
	}
	return (*this);
}

Point::~Point()
{

}

const Fixed Point::get_x() const
{
	return (this->x);
}

const Fixed Point::get_y() const
{
	return (this->y);
}
