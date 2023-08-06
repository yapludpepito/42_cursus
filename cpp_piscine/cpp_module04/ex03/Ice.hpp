#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{

	public :
		Ice();
		Ice(const Ice &);
		~Ice();
		void use(ICharacter& target);
		Ice &operator=(const Ice &);
		Ice* clone() const;
};



#endif