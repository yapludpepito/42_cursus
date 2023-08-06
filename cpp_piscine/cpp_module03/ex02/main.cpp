#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main(void)
{
    FragTrap a("alo");
    FragTrap b(a);
    FragTrap c;

	c.attack("alo");

    c = b;

	c.attack("alo");
    a.attack("Jason");
    a.HighFivesGuys();
    a.beRepaired(10);
    a.takeDamage(2);
    for (int i = 0; i < 100; i++)
        a.attack("Jason");
}