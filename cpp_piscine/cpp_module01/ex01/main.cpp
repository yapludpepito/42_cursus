#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie;
	Zombie	*zomb;

	zomb = zombie.zombieHorde(5, "jul");
	delete []zomb;
	return (0);
}