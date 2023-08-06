#include <iostream>
#include <fstream>


std::string ft_replace(std::string line, std::string s1, std::string s2)
{
	size_t	j=0;
	std::string dup = line;

	while (1)
	{
		j = dup.rfind(s1);
		if (j > dup.length())
			return line;
		line.erase(j, s1.length());
		dup.erase(j, s1.length());
		line.insert(j, s2);
	}
}

int	main(int argc, char **argv)
{
	std::string	line;
	if (argc != 4)
	{
		std::cout << "Error missing or too many arg\n";
		return (1);
	}
	line = argv[2];
	if (line == "")
	{
		std::cout << "Error nothing to sed\n";
		return (1);
	}
	std::ifstream infile(argv[1]);
	std::string outfile = argv[1];
	outfile += ".replace";
	if (infile.is_open())
	{
		std::ofstream ofile(outfile.c_str());
		if (ofile.is_open())
		{
			while (getline(infile, line))
			{
				line = ft_replace(line, argv[2], argv[3]);
				ofile << line;
				ofile << "\n";
			}
		}
		else
			std::cout << "Error can't open the outfile\n";
	}
	else
		std::cout << "Error can't open the infile\n";
	return (0);
}