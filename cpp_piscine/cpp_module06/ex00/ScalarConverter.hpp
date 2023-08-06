#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
    private :
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const &ref);
        ScalarConverter &operator=(ScalarConverter const &ref);
    public :
        static void    convert_from_char(std::string);
        static void    convert_from_int(std::string);
        static void    convert_from_float(std::string);
        static void    convert_from_double(std::string);
        static void    weird_convert_double(std::string);
        static void    weird_convert_float(std::string);
};



#endif