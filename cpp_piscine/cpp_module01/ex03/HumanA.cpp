#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->arme.getType() << std::endl;
}


HumanA::HumanA(std::string nam, Weapon &arm) : name(nam), arme(arm)
{
	return ;
}

HumanA::~HumanA()
{

}