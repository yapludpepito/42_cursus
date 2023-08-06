#include "Animal.hpp"



Animal::Animal()
{
	this->type = "Cat";
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal created\n";
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal created\n";
	*this = animal;
}

Animal::~Animal()
{
	std::cout << "Animal destroyed\n";
}

Animal &Animal::operator=(const Animal &animal)
{
	if (this != &animal)
		this->type = animal.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "**sound of animal**\n";
}

std::string	Animal::get_Type() const
{
	return (this->type);
}
