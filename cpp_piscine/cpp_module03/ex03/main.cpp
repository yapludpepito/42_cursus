#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap a("CouCou");
	DiamondTrap b(a);
	DiamondTrap c;

	c = b;

	a.beRepaired(50);
	a.attack("jul");
	for (int i = 0; i < 51; i++)
		a.attack("jul");
	a.whoAmI();
}