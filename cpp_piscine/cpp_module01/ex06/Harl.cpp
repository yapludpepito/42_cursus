#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !";
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !";
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable ! I want to speak to the manager now.";
}

void	Harl::complain( std::string level )
{
	void	(Harl::*ptr_debug) (void);
	void	(Harl::*ptr_info) (void);
	void	(Harl::*ptr_warning) (void);
	void	(Harl::*ptr_error) (void);

	ptr_debug = &Harl::debug;
	ptr_info = &Harl::info;
	ptr_error = &Harl::error;
	ptr_warning = &Harl::warning;
	std::string	answer[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int i = 0;
	while (i < 4)
	{
		if (answer[i] == level)
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			(this->*ptr_debug)();
			std::cout << std::endl;
			(this->*ptr_info)();
			std::cout << std::endl;
			(this->*ptr_warning)();
			std::cout << std::endl;
			(this->*ptr_error)();
			std::cout << std::endl;
			break;

		case 1:
			(this->*ptr_info)();
			std::cout << std::endl;
			(this->*ptr_warning)();
			std::cout << std::endl;
			(this->*ptr_error)();
			std::cout << std::endl;
			break;
		
		case 2:
			(this->*ptr_warning)();
			std::cout << std::endl;
			(this->*ptr_error)();
			std::cout << std::endl;
			break;

		case 3:
			(this->*ptr_error)();
			std::cout << std::endl;
			break;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}
