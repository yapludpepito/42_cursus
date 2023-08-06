#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	protected :
		std::string		Name;
		int				HitPoints;
		int				EnergyPoints;
		int				AttackDamage;

	public :
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &);
		virtual void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};



#endif