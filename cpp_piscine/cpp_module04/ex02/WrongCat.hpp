#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{


	public :
		WrongCat();
		WrongCat(const WrongCat &);
		~WrongCat();
		void makeSound(void) const;
		WrongCat &operator=(const WrongCat &);
};

#endif