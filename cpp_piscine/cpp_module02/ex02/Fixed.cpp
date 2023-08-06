#include "Fixed.hpp"

const int	Fixed::nb_bits = 8;

Fixed::Fixed()
{
	this->nb = 0;
}

Fixed::Fixed(const Fixed &p)
{
	*this = p;
}

Fixed	&Fixed::operator=(const Fixed &p)
{
	this->nb = p.getRawBits();
	return (*this);
}

Fixed::Fixed(const int number)
{
	setRawBits(number);
}

Fixed::Fixed(const float number)
{
	this->nb = roundf(number * (1 << nb_bits));
}

Fixed::~Fixed()
{
}

void	Fixed::setRawBits( int const raw )
{
	this->nb = raw << nb_bits;
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


int	Fixed::getRawBits( void ) const
{
	return (this->nb);
}

std::ostream	&operator<<(std::ostream& os,Fixed const &number)
{
	os << number.toFloat();
	return (os);
}

Fixed Fixed::operator+(const Fixed &nb)
{
	Fixed a = (this)->toFloat() + nb.toFloat();
	return (a);
}

Fixed Fixed::operator-(const Fixed &nb)
{
	Fixed a = this->toFloat() - nb.toFloat();
	return (a);
}

Fixed Fixed::operator*(const Fixed &nb)
{
	Fixed a = this->toFloat() * nb.toFloat();
	return (a);
}

Fixed Fixed::operator/(const Fixed &nb)
{
	Fixed a = this->toFloat() / nb.toFloat();
	return (a);
}

bool Fixed::operator<(const Fixed &nb) const
{
	bool a = this->toFloat() < nb.toFloat();
	return (a);
}

bool Fixed::operator>(const Fixed &nb) const
{
	bool a = this->toFloat() > nb.toFloat();
	return (a);
}

bool Fixed::operator<=(const Fixed &nb)
{
	bool a = this->toFloat() <= nb.toFloat();
	return (a);
}

bool Fixed::operator>=(const Fixed &nb)
{
	bool a = this->toFloat() >= nb.toFloat();
	return (a);
}

bool Fixed::operator==(const Fixed &nb)
{
	bool a = this->toFloat() == nb.toFloat();
	return (a);
}

bool Fixed::operator!=(const Fixed &nb)
{
	bool a = this->toFloat() != nb.toFloat();
	return (a);
}


const Fixed	&Fixed::min(Fixed const &nb1, Fixed const &nb2)
{
	if (nb1 < nb2)
		return (nb1);
	else 
		return (nb2);
}

Fixed	&Fixed::min(Fixed &nb1, Fixed &nb2)
{
	if (nb1 < nb2)
		return (nb1);
	else 
		return (nb2);
}

const Fixed	&Fixed::max(const Fixed &nb1, const Fixed &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	else 
		return (nb2);
}

Fixed	&Fixed::max(Fixed &nb1, Fixed &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	else
		return (nb2);
}

Fixed Fixed::operator++(int i)
{
	(void)i;
	Fixed a = *this;
	this->nb++;
	return (a);
}

Fixed Fixed::operator--(int i)
{
	(void)i;
	Fixed a = *this;
	this->nb--;
	return (a);
}

Fixed &Fixed::operator++()
{
	this->nb++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->nb--;
	return (*this);
}