#include "Fixed.hpp"

const int	Fixed::nb_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->nb = 0;
}

Fixed::Fixed(const Fixed &p)
{
	std::cout << "Copy constructor called\n";
	*this = p;
}

Fixed	&Fixed::operator=(const Fixed &p)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &p)
		this->nb = p.getRawBits();
	return (*this);
}

Fixed::Fixed(const int number)
{
	std::cout << "int constructor called\n";
	setRawBits(number << nb_bits);
}

Fixed::Fixed(const float number)
{
	std::cout << "float constructor called\n";
	this->nb = roundf(number * (1 << nb_bits));
}

Fixed::~Fixed()
{
	std::cout << "destructor called\n";
}

void	Fixed::setRawBits( int const raw )
{
	this->nb = raw;
}

int	Fixed::getRawBits( void ) const
{
	return (this->nb);
}

float	Fixed::toFloat( void ) const
{
	float a = (float)this->getRawBits() / (1 << nb_bits);
	return (a);
}

int	Fixed::toInt( void ) const
{
	int a = this->nb >> nb_bits;
	return (a);
}


std::ostream	&operator<<(std::ostream& os,Fixed const &number)
{
	os << number.toFloat();
	return (os);
}
