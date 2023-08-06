#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie;
	Zombie	*zomb;

	zomb = zombie.newZombie("jul");
	zomb->randomChump("coucou");
	zombie.announce();
	delete zomb;
}