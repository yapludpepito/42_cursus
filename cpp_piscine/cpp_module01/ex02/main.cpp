#include <iostream>

int main(void)
{
	std::string	hello = "HI THIS IS BRAIN";
	std::string *ptrString = &hello;
	std::string &refString = hello;

	std::cout << &hello << std::endl << ptrString << std::endl << &refString << std::endl;
	std::cout << hello << std::endl << *ptrString << std::endl << refString << std::endl;
}