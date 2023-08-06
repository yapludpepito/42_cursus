#include "HumanB.hpp"

void	HumanB::attack()
{
	if (this->arme)
		std::cout << this->name << " attacks with their " << this->arme->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &arme)
{
	this->arme = &arme;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::HumanB()
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}