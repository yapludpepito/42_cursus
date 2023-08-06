#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
	{
		std::cout << "Error need an input file" << std::endl;
        return (0);
	}
	try
	{
		std::string csv = "data.csv";
		std::string txt = argv[1];
		if (txt.empty() == true)
		{
			std::cout << "Error invalid filename\n";
			return (1);
		}
		BitcoinExchange::for_csv(csv, txt);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}