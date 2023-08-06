#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	
	public :
		Cure();
		Cure(const Cure &);
		~Cure();
		void use(ICharacter& target);
		Cure &operator=(const Cure &);
		Cure* clone() const;
};

#endif