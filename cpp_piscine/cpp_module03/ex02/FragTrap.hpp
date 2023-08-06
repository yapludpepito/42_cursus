#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
    public :
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &);
		~FragTrap();
		FragTrap &operator=(const FragTrap &);
        void    HighFivesGuys(void);
};





#endif