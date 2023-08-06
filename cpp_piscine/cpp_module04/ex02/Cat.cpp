#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "cat created\n";
	brain = new Brain();
	this->makeSound();
}

Cat::Cat(const Cat &cat): Animal("Cat")
{
	std::cout << "cat created\n";
	this->brain = NULL;
	*this = cat;
}

void Cat::makeSound(void) const
{
	std::cout << "Miaou\n";
}

Cat::~Cat()
{
	delete(this->brain);
	std::cout << "Cat Destroyed\n";
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this != &cat)
	{
		this->type = cat.type;
		if (this->brain)
			delete (this->brain);
		this->brain = new Brain(*(cat.brain));
	}
	return (*this);
}