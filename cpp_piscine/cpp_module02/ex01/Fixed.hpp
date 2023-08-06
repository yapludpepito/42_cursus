#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <sstream>
#include <cmath>


class	Fixed
{
	private:
		int					nb;
		static const int	nb_bits;

	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed&);
		Fixed &operator=(const Fixed&);
		~Fixed();
		float toFloat( void ) const;
		int toInt( void ) const;
		void setRawBits( int const raw );
		int getRawBits( void ) const;
};

std::ostream	&operator<<(std::ostream& os, Fixed const &number);

#endif