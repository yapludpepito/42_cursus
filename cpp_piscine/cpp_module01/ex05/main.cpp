#include "Harl.hpp"

int	main(void)
{
	std::string	alo;

	Harl test;
	std::cout << "test info : ";
	test.complain("INFO");
	std::cout << std::endl ;
	std::cout << "test warning : ";
	test.complain("WARNING");
	std::cout << std::endl ;
	std::cout << "test error : ";
	test.complain("ERROR");
	std::cout << std::endl ;
	std::cout << "test debug : ";
	test.complain("DEBUG");
	std::cout << std::endl ;
	std::cout << "test invalid : ";
	test.complain("alo");
	std::cout << std::endl ;
}