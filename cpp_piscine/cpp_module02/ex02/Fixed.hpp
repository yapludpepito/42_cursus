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
		Fixed operator+(const Fixed&);
		Fixed operator-(const Fixed&);
		Fixed operator*(const Fixed&);
		Fixed operator/(const Fixed&);
		Fixed operator++(int i);
		Fixed operator--(int i);
		Fixed &operator++();
		Fixed &operator--();
		bool operator<(const Fixed&) const ;
		bool operator>(const Fixed &nb) const ;
		bool operator<=(const Fixed&);
		bool operator>=(const Fixed&);
		bool operator==(const Fixed&);
		bool operator!=(const Fixed&);
		~Fixed();
		float toFloat( void ) const;
		int toInt( void ) const;
		void setRawBits( int const raw );
		int getRawBits( void ) const;
		static const Fixed &min(const Fixed &nb1, const Fixed &nb2);
		static Fixed &min(Fixed &nb1, Fixed &nb2);
		static const Fixed &max(const Fixed &nb1, const Fixed &nb2);
		static Fixed &max(Fixed &nb1, Fixed &nb2);
};

std::ostream	&operator<<(std::ostream& os, Fixed const &number);

#endif