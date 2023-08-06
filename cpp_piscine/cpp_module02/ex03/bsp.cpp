#include "Point.hpp"

Fixed determinant(Fixed a, Fixed b, Fixed c, Fixed d, Fixed e, Fixed f, Fixed g, Fixed h, Fixed i)
{
	return (a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed alpha = determinant(point.get_x(), point.get_y(), 1.0f, c.get_x(), c.get_y(), 1.0f, b.get_x(), b.get_y(), 1.0f) / determinant(a.get_x(), a.get_y(), 1.0f, c.get_x(), c.get_y(), 1.0f, b.get_x(), b.get_y(), 1.0f);
	Fixed beta = determinant(a.get_x(), a.get_y(), 1.0f, point.get_x(), point.get_y(), 1.0f, c.get_x(), c.get_y(), 1.0f) / determinant(a.get_x(), a.get_y(), 1.0f, b.get_x(), b.get_y(), 1.0f, c.get_x(), c.get_y(), 1.0f);
	Fixed gamma = determinant(a.get_x(), a.get_y(), 1.0f, b.get_x(), b.get_y(), 1.0f, point.get_x(), point.get_y(), 1.0f) / determinant(a.get_x(), a.get_y(), 1.0f, b.get_x(), b.get_y(), 1.0f, c.get_x(), c.get_y(), 1.0f);
	if (alpha > 0.0f && alpha < 1.0f && beta > 0.0f && beta < 1.0f && gamma > 0.0f && gamma < 1.0f) 
		return (true);
	return (false);
}
