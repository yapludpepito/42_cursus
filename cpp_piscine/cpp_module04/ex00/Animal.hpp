#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{

	protected :
		std::string	type;

	public :
		Animal();
		Animal(std::string type);
		Animal(const Animal &);
		virtual~Animal();
		Animal &operator=(const Animal &);
		std::string	get_Type() const ;
		virtual void	makeSound() const;

};



#endif