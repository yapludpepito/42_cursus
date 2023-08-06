#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(), FragTrap(), ScavTrap()
{
	this->Name = name;
	ClapTrap::Name = name + "_clap_name";
	std::cout << "Shiny DiamondTrap " << name << " entered the room!\n";
}

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	this->Name = "jul";
	std::cout << "Default constructor from diamond call\n";

}

DiamondTrap::DiamondTrap(const DiamondTrap &trap) : ClapTrap(trap.Name + "_clap_trap"), FragTrap(), ScavTrap()
{
	*this = trap;
	std::cout << "copy constructor from diamond called\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "destroyed Diamond\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &trap)
{
	if (this != &trap)
	{
		this->Name = trap.Name;
		this->EnergyPoints = trap.EnergyPoints;
		this->HitPoints = trap.HitPoints;
		this->AttackDamage = trap.AttackDamage;
	}
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->Name << " and my ClapTrap name is " << ClapTrap::Name << std::endl;
}
