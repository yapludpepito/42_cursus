#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}


Zombie::Zombie()
{
	this->name = "Default Zombie\n";
}

Zombie::~Zombie()
{
	std::cout << "destroy " << this->name << std::endl; 
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}
