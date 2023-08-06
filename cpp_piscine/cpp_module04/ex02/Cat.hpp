#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	Brain *brain;
	
	public :
		Cat();
		Cat(const Cat &);
		~Cat();
		virtual void makeSound(void) const;
		Cat &operator=(const Cat &);
};

#endif