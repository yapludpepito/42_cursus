#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog created\n";
	this->makeSound();
}

Dog::Dog(const Dog &Dog): Animal("Dog")
{
	std::cout << "Dog created\n";
	*this = Dog;
}

void Dog::makeSound(void) const
{
	std::cout << "WOUAF\n";
}

Dog::~Dog()
{
	std::cout << "Dog Destroyed\n";
}

Dog &Dog::operator=(const Dog &Dog)
{
	if (this != &Dog)
		this->type = Dog.type;
	return (*this);
}