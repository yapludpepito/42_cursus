#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int n, std::string name)
{
	int i = 0;
	Zombie *zomb = new Zombie[n];

	while (i < n)
	{
		zomb[i].setName(name);
		zomb[i].announce();
		i++;
	}
	return (zomb);
}