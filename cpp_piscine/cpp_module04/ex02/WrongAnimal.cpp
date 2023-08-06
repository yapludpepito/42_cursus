#include "WrongAnimal.hpp"



WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal created\n";
	this->type = "Cat";
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal created\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	std::cout << "WrongAnimal created\n";
	*this = animal;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
	if (this != &animal)
		this->type = animal.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "**Sounds from wrong animal**\n";
}

std::string	WrongAnimal::get_Type() const
{
	return (this->type);
}
