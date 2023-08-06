#include "WrongAnimal.hpp"



WrongAnimal::WrongAnimal()
{
	this->type = "Cat";
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal created\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	*this = animal;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
	*this = animal;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "**Bruit d'animal**";
}

std::string	WrongAnimal::get_Type() const
{
	return (this->type);
}
