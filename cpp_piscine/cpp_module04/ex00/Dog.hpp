#ifndef DOG_HPP
#define DOH_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog(const Dog &);
		~Dog();
		virtual void makeSound() const;
		Dog &operator=(const Dog &);
};



#endif