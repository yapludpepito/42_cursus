#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->Name = "NoName";
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
	std::cout << "default constructor\n";
}

ClapTrap::ClapTrap(std::string name)
{
	this->Name = name;
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
	std::cout << "string constructor\n";
}

ClapTrap::ClapTrap(const ClapTrap &clap)
{
	*this = clap;
	std::cout << "copy constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "destruction of a ClapTrap\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clap)
{
	if (this != &clap)
	{
		this->Name = clap.Name;
		this->EnergyPoints = clap.EnergyPoints;
		this->HitPoints = clap.HitPoints;
		this->AttackDamage = clap.AttackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!\n";
		this->EnergyPoints--;
	}
	else
		std::cout << "no energy point to do this or dead\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->HitPoints -= amount;
	std::cout << "ClapTrap has take " << amount << " damage\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		std::cout << "ClapTrap " << this->Name << " repairs for " << amount << " life points\n";
		this->HitPoints += amount;
		this->EnergyPoints--;
	}
	else
		std::cout << "no energy point to do this or dead\n";
}
