#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap
{
    public :
        ScavTrap();
        ScavTrap(std::string name);
        void GuardGate();
        ScavTrap(const ScavTrap &);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &);

};




#endif