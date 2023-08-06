#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

	public :

	void	attack();
	void	setWeapon(Weapon &arme);
	HumanB(std::string name);
	HumanB();
	~HumanB();

	private :

	Weapon		*arme;
	std::string	name;
};

#endif