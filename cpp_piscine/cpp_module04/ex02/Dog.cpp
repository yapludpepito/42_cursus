#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog created\n";
	this->brain = new Brain();
	this->makeSound();
}

Dog::Dog(const Dog &Dog): Animal("Dog")
{
	std::cout << "Dog created\n";
	this->brain = NULL;
	*this = Dog;
}


void Dog::makeSound(void) const
{
	std::cout << "WOUAF\n";
}

Dog::~Dog()
{
	delete(this->brain);
	std::cout << "Dog Destroyed\n";
}

Dog &Dog::operator=(const Dog &Dog)
{
	if (this != &Dog)
	{
		this->type = Dog.type;
		if (this->brain)
			delete (this->brain);
		this->brain = new Brain(*(Dog.brain));
	}
	return (*this);
}