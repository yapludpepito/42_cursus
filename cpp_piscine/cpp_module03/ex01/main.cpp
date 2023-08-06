#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap a("alo");
    ScavTrap b(a);
    ScavTrap c;

    c = b;


    a.attack("Jason");
    a.GuardGate();
    a.beRepaired(10);
    a.takeDamage(2);
    for (int i = 0; i < 50; i++)
        a.attack("Jason");
}