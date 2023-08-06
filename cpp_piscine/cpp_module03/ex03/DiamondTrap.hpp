#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private :
        std::string Name;

    public :
        using FragTrap::HitPoints;
        using FragTrap::AttackDamage;
        using ScavTrap::EnergyPoints;
        using ScavTrap::attack;
        DiamondTrap(std::string name);
        DiamondTrap();
        DiamondTrap(const DiamondTrap &trap);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap &);
        void whoAmI();
};




#endif