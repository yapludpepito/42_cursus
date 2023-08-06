#ifndef DOG_HPP
#define DOH_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{

		Brain *brain;
	public :
		Dog();
		Dog(const Dog &);
		~Dog();
		virtual void makeSound() const;
		Dog &operator=(const Dog &);
};



#endif