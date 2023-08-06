#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie()
{
	this->name = "jul";
}

Zombie::~Zombie()
{
	std::cout << "destroy " << this->name << std::endl; 
}