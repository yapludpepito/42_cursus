#include "AMateria.hpp"


AMateria::AMateria()
{
	this->type = "AMateria";
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &AMateria)
{
	*this = AMateria;
}

AMateria::~AMateria()
{}

AMateria &AMateria::operator=(const AMateria &AMateria)
{
	this->type = AMateria.get_Type();
	return (*this);
}

std::string const	&AMateria::get_Type() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout <<  "Using a AMateria on " << target.getName() << std::endl;
}
