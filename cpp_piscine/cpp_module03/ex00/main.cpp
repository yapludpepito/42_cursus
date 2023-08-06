#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("le plus fort de tous");
	ClapTrap b(a);
	ClapTrap c;

	b = c;

	a.attack("jul");
	a.beRepaired(20);
	a.takeDamage(20);
	for (int i = 0; i < 10; i++)
		a.attack("jul");
}
