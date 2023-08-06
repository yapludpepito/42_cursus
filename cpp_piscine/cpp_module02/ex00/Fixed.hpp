#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int					nb;
		static const int	nb_bits;

	public:
		Fixed();
		Fixed(const Fixed&);
		Fixed &operator=(const Fixed&);
		~Fixed();
		void setRawBits( int const raw );
		int getRawBits( void ) const;
};

#endif