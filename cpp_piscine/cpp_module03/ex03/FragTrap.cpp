#include "FragTrap.hpp"
#include <iostream>


FragTrap::FragTrap() : ClapTrap()
{
    this->Name = "DefaultName";
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << "FragTrap Default constructor called\n";
}


FragTrap::FragTrap(std::string name) : ClapTrap()
{
    this->Name = name;
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << "FragTrap string constructor called\n";
}

void FragTrap::HighFivesGuys(void)
{
    if (this->HitPoints > 0)
        std::cout << "High Fives !!!!\n";
}

FragTrap::FragTrap(const FragTrap &trap) : ClapTrap()
{
    *this = trap;
    std::cout << "copy constructor from FragTrap called\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destroyed\n";
}

FragTrap &FragTrap::operator=(const FragTrap &trap)
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
