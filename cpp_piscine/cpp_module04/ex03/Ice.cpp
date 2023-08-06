#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice &Ice): AMateria("ice")
{
	*this = Ice;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &Ice)
{
	if (this != &Ice)
		AMateria::operator=(Ice);
	return (*this);
}

Ice* Ice::clone() const
{
	Ice *a = new Ice(*this);
	return (a);
}
