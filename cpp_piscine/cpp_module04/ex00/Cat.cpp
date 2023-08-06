#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "cat created\n";
	this->makeSound();
}

Cat::Cat(const Cat &cat): Animal("Cat")
{
	std::cout << "cat created\n";
	*this = cat;
}

void Cat::makeSound(void) const
{
	std::cout << "Miaou\n";
}

Cat::~Cat()
{
	std::cout << "Cat Destroyed\n";
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this != &cat)
		this->type = cat.type;
	return (*this);
}
