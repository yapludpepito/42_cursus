#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->Name = "DefaultName";
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << "ScavTrap Default constructor called\n";
}


ScavTrap::ScavTrap(std::string name) : ClapTrap()
{
    this->Name = name;
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << "ScavTrap string constructor called\n";
}

void ScavTrap::GuardGate()
{
    if (this->HitPoints > 0)
    std::cout << "ScavTrap is now in Gate keeper mode\n";
}

ScavTrap::ScavTrap(const ScavTrap &trap) : ClapTrap()
{
    *this = trap;
    std::cout << "copy constructor from ScavTrap called\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "Scav destroyed\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &trap)
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
