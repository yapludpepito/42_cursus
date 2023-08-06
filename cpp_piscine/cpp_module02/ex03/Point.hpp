#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point 
{
	private :
		const Fixed x;
		const Fixed y;

	public :
		Point();
		Point(float x, float y);
		Point(const Point&);
		Point &operator=(const Point&);
		~Point();
		const Fixed get_x() const;
		const Fixed get_y() const;

};

Fixed determinant(Fixed a, Fixed b, Fixed c, Fixed d, Fixed e, Fixed f, Fixed g, Fixed h, Fixed i);
bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif