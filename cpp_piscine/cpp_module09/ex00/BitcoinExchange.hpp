#ifndef __BITCOINEXCHANGE_H__
#define __BITCOINEXCHANGE_H__

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <exception>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

class BitcoinExchange{
    private :
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange& target);
        BitcoinExchange &operator=(BitcoinExchange& target);
        ~BitcoinExchange();

    public :
        static  void    for_txt(std::map<std::string, double> _price, std::string txt);
        static  bool    leap_year(int year);
        static  bool    check_date(std::string date);
        static  void    ft_algo(std::map<std::string, double> _price, std::string key, std::string value);
        static  void    for_csv(std::string csv, std::string txt);
};


#endif // __BITCOINEXCHANGE_H__