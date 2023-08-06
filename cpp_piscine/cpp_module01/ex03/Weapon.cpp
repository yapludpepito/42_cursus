#include "Weapon.hpp"

std::string	&Weapon::getType()
{
	std::string &refStr = this->type;

	return (refStr);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::Weapon()
{
	this->type = "arme de fou";
}

Weapon::~Weapon()
{
	return ;	
}