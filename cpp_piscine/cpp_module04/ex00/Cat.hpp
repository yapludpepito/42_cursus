#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{


	public :
		Cat();
		Cat(const Cat &);
		~Cat();
		virtual void makeSound(void) const;
		Cat &operator=(const Cat &);
};

#endif