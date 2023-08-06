#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    
}

BitcoinExchange::BitcoinExchange(BitcoinExchange& target)
{
    (void)target;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& target)
{
    (void)target;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    
}

void BitcoinExchange::for_txt(std::map<std::string, double> _price, std::string txt)
{
    std::ifstream fin(txt.c_str());
	bool check = true;
	if (!fin)
		throw std::invalid_argument("invalid file");
	std::string value;
	std::string key;
	if (!(std::getline(fin, value)))
		throw std::invalid_argument("invalid file");
	if (value != "date | value")
		throw std::invalid_argument("Invalid file");
	while (std::getline(std::getline(fin, key, '|'), value))
	{
		while (key.find("\n") != std::string::npos)
		{
			std::cout << "Error : missing value" << std::endl;
			key = key.substr(key.find("\n") + 1, key.length() - 1);
		}
		if (key.empty() == false)
		{
			if (key.rfind(" ") != std::string::npos)
				key = key.substr(0, key.rfind(" "));
			if (value.rfind("123456789.") > value.rfind(" ") && value.rfind(" ") != 0)
			{
				std::cout << "Error invalid value : " << value << std::endl;
				check = false;
			}
			for (unsigned int i = 0; i < key.length(); i++)
			{
				if (check == true && ((((i < 4 || (i > 4 && i < 7) || (i > 7 && i < 10)) && (key.at(i) < '0' || key.at(i) > '9')) || ((i == 4 || i == 7) && key.at(i) != '-')) || key.length() != 10))
				{
					std::cout << "Erorr invalid date" << std::endl;
					check = false;
				}
			}
			while (check == true && value.rfind(" ") != std::string::npos && value.rfind(" ") != 0)
				value = value.substr(0, value.rfind(" "));
			while (check == true && value.find(" ") != std::string::npos)
				value = value.substr(value.find(" ") + 1, value.length() - 1);
			if (check == true && value.find(".") != value.rfind("."))
				std::cout << "Error invalid value : " << value << std::endl;
			else if (check == true && value.find_first_not_of("0123456789.") != std::string::npos)
				std::cout << "Error invalid value : " << value << std::endl;
			else if (check == true && (std::strtod(value.c_str(), NULL) > 1000 || std::strtod(value.c_str(), NULL) < 0))
				std::cout << "Error invalid value : " << value << std::endl;
			else if (check == true && check_date(key) == true)
				ft_algo(_price, key, value);
			else if (check == true)
				std::cout << "Erorr invalid date" << std::endl;
			check = true;
		}
	}
}

bool BitcoinExchange::leap_year(int year)
{
    if (year % 4 == 0) 
	{
        if (year % 100 == 0) 
		{
            if (year % 400 == 0) 
                return true;
			else 
                return false;
        } 
		else 
            return true;
    }
	else 
        return false;
}

bool BitcoinExchange::check_date(std::string date)
{
    struct tm tm;
	char *to_check = strptime(date.c_str(), "%Y-%m-%d", &tm);
	tm.tm_year += 1900;
	if (to_check == NULL || *to_check != '\0')
		return false;
	if (tm.tm_year < 1900 || tm.tm_year > 2050)
		return false;
	else if (tm.tm_mon == 1 && tm.tm_mday == 29 && leap_year(tm.tm_year) == false)
		return false;
	else if (tm.tm_mon == 1 && tm.tm_mday > 29)
		return false;
	else if ((tm.tm_mon == 3 || tm.tm_mon == 5 || tm.tm_mon == 8 || tm.tm_mon == 10) && tm.tm_mday == 31)
		return false;
	return true;
}

void BitcoinExchange::ft_algo(std::map<std::string, double> _price, std::string key, std::string value)
{
    std::map<std::string, double>::const_iterator it;
    it = _price.upper_bound(key);
    if (it != _price.begin())
        it--;
    if (it == _price.end())
        return ;
    double result = it->second * std::strtod(value.c_str(), NULL);\
    std::cout << "in "<< it->first << " value : " << result << std::endl;
}

void BitcoinExchange::for_csv(std::string csv, std::string txt)
{
    std::map<std::string, double> _price;
	std::ifstream fin(csv.c_str());
	if (!fin)
		throw std::invalid_argument("Invalid file");
	std::string	value;
	std::string	key;
	if (fin.is_open() == false)
		std::cout << "Error: cannot open file " << csv << std::endl; 
	if (!std::getline(std::getline(fin, key, ','), value)) 
		std::cout << "Error empty file : " << csv << std::endl;
	while (std::getline(std::getline(fin, key, ','), value))
		_price[key] = std::strtod(value.c_str(), NULL);
	for_txt(_price, txt);
}
