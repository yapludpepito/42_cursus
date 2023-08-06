#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

	private :

	std::string	name;

	public :

	void	announce(void);
	void	setName(std::string name);
	void	randomChump( std::string name );
	Zombie*	newZombie( std::string name );
	Zombie* zombieHorde( int N, std::string name );

	Zombie(std::string name);
	Zombie();
	~Zombie();

};

#endif