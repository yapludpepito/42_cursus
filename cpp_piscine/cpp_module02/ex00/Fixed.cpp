#include "Fixed.hpp"

static const int nb_bits = 8;

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

Fixed::~Fixed()
{
	std::cout << "destructor called\n";
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (this->nb);
}

void	Fixed::setRawBits( int const raw )
{
	this->nb = raw;
}
