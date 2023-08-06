#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &ref) { (void)ref; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &ref) {(void)ref; return (*this);}

void    ScalarConverter::convert_from_char(std::string arg)
{
    std::cout << "Char : " << arg << std::endl;
    std::cout << "Int : " << static_cast<int>(arg.at(0)) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Float : " << static_cast<float>(arg.at(0)) << "f\n";
    std::cout << "Double : " << static_cast<double>(arg.at(0)) << std::endl;
}

void    ScalarConverter::convert_from_int(std::string arg)
{
    int a;
    std::stringstream is(arg);
        
    is >> a;
    std::cout << "convert from a int\n";
    if (a < 33 || a > 126)
        std::cout << "Char : Non displayable\n";
    else
        std::cout << "Char : " << static_cast<char>(a) << std::endl;
    if (arg.length() >= 10 && arg.compare("2147483647") > 0)
    {
        std::cout << "Int : Overflow\n";
        std::cout << "Float : +inf\n";
        std::cout << "Double : +inf\n";
    }
    else if (arg.length() >= 11 && arg.compare("-2147483648") > 0)
    {
        std::cout << "Int : Underflow\n";
        std::cout << "Float : -inf\n";
        std::cout << "Double : -inf\n";
    }
    else
    {
        std::cout << "Int : " << a << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "Float : " << static_cast<float>(a) << "f\n";
        std::cout << "Double : " << static_cast<double>(a) << std::endl;
    }
}

void    ScalarConverter::convert_from_float(std::string arg)
{
    float a;
    std::stringstream is(arg);

    if (std::strtof(arg.c_str(), NULL) == HUGE_VALF)
    {
        std::cout << "char : Impossible\n";
        std::cout << "int : overflow\n";
        std::cout << "double : +inf\n";
        std::cout << "float : +inff\n";
    }
    else if (std::strtof(arg.c_str(), NULL) == -HUGE_VALF)
    {
        std::cout << "char : Impossible\n";
        std::cout << "int : underflow\n";
        std::cout << "double : -inf\n";
        std::cout << "float : -inff\n";
    }
    else
    {
        is >> a;
        std::cout << "convert from a float\n";
        if (a < 33 || a > 126 || a / static_cast<int>(a) != 1)
            std::cout << "Char : Non displayable\n";
        else
            std::cout << "Char : " << static_cast<char>(a) << std::endl;
        if (arg.find(".") > 10 || (arg.find(".") >= 10 && arg.compare("2147483647") > 0))
            std::cout << "Int : Overflow" << std::endl;
        else if (arg.find(".") >= 11 && arg.compare("-2147483648") > 0)
            std::cout << "Int : Uderflow" << std::endl;
        else 
            std::cout << "Int : " <<  static_cast<int>(a) << std::endl;
        std::cout << std::fixed;
        std::cout << std::setprecision(5);
        std::cout << "Float : " << a << "f\n";
        std::cout << std::setprecision(5);
        std::cout << "Double : " << static_cast<double>(a) << "\n";
    }
}

void    ScalarConverter::convert_from_double(std::string arg)
{
    double a = std::strtod(arg.c_str(), NULL);

    std::cout << "convert from a double\n";
    if (std::strtod(arg.c_str(), NULL) == HUGE_VAL)
    {
        std::cout << "char : Impossible\n";
        std::cout << "int : overflow\n";
        std::cout << "double : +inf\n";
        std::cout << "float : +inff\n";
    }
    else if (std::strtod(arg.c_str(), NULL) == -HUGE_VAL)
    {
        std::cout << "char : Impossible\n";
        std::cout << "int : underflow\n";
        std::cout << "double : -inf\n";
        std::cout << "float : -inff\n";
    }
    else
    {
        if (a < 33 || a > 126 || a / static_cast<int>(a) != 1)
            std::cout << "Char : Non displayable " << std::endl;
        else
            std::cout << "Char : " << static_cast<char>(a) << std::endl;
        if (arg.find(".") > 10 || (arg.find(".") >= 10 && arg.compare("2147483647.") > 0))
            std::cout << "Int : Overflow" << std::endl;
        else if (arg.find(".") >= 11 && arg.compare("-2147483648") > 0)
            std::cout << "Int : Uderflow" << std::endl;
        else 
            std::cout << "Int : " <<  static_cast<int>(a) << std::endl;
        std::cout << std::fixed;
        std::cout << std::setprecision(5);
        std::cout << "Float : " << static_cast<float>(a) << "f\n";
        std::cout << std::setprecision(14);
        std::cout << "Double : " << a << "\n";
    }
}

void    ScalarConverter::weird_convert_double(std::string arg)
{
    if (arg == "-inf")
    {
        std::cout << "char : Impossible\n";
        std::cout << "int : underflow\n";
        std::cout << "double : -inf\n";
        std::cout << "float : -inff\n";
    }
    else if (arg == "+inf")
    {
        std::cout << "char : Impossible\n";
        std::cout << "int : overflow\n";
        std::cout << "double : +inf\n";
        std::cout << "float : +inff\n";
    }
    else
    {
        std::cout << "char : Impossible\n";
        std::cout << "int : impossible\n";
        std::cout << "double : nan\n";
        std::cout << "float : nanf\n";
    }
}

void    ScalarConverter::weird_convert_float(std::string arg)
{
    if (arg == "-inff")
    {
        std::cout << "char : Impossible\n";
        std::cout << "int : underflow\n";
        std::cout << "double : -inf\n";
        std::cout << "float : -inff\n";
    }
    else if (arg == "+inff")
    {
        std::cout << "char : Impossible\n";
        std::cout << "int : overflow\n";
        std::cout << "double : +inf\n";
        std::cout << "float : +inff\n";
    }
    else
    {
        std::cout << "char : Impossible\n";
        std::cout << "int : impossible\n";
        std::cout << "double : nan\n";
        std::cout << "float : nanf\n";
    }
}
