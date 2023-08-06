#ifndef AMateria_HPP
#define AMateria_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{

	protected :
		std::string	type;

	public :
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &);
		AMateria &operator=(const AMateria &);
		virtual ~AMateria();
		std::string	const &get_Type() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};



#endif