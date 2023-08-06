#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "Wrongcat created\n";
	this->makeSound();
}

WrongCat::WrongCat(const WrongCat &Wrongcat): WrongAnimal("WrongCat")
{
	std::cout << "Wrongcat created\n";
	*this = Wrongcat;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Miaou\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destroyed\n";
}

WrongCat &WrongCat::operator=(const WrongCat &Wrongcat)
{
	if (this != &Wrongcat)
		this->type = Wrongcat.type;
	return (*this);
}
