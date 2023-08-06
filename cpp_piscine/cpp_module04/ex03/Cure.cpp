#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{}

Cure::Cure(const Cure &Cure): AMateria("cure")
{
	*this = Cure;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

Cure::~Cure()
{}

Cure &Cure::operator=(const Cure &Cure)
{
	AMateria::operator=(Cure);
	return (*this);
}

Cure* Cure::clone() const
{
	Cure *a = new Cure(*this);
	return (a);
}

