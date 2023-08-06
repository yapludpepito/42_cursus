#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (0);
    std::string arg = argv[1];
    if (arg.empty() == false)
    {
        if (arg == "-inf" || arg == "+inf" || arg == "nan")
            ScalarConverter::weird_convert_double(arg);
        else if (arg == "-inff" || arg == "+inff" || arg == "nanf")
            ScalarConverter::weird_convert_float(arg);
        else if (arg.length() == 1 && (arg.at(0) < '0' || arg.at(0) > '9'))
            ScalarConverter::convert_from_char(argv[1]);
        else if ((arg.find('.') > arg.length() && ((arg.at(0) <= '9' && arg.at(0) >= '0') || arg.at(0) == '-')) && ((arg.length() < arg.find_first_not_of("0123456789-")) || (arg.find_last_not_of("0123456789-") == 1)))
            ScalarConverter::convert_from_int(argv[1]);
        else if (arg.at(arg.length() - 1) == 'f' && arg.find_first_not_of("0123456789f-.") > arg.length())
            ScalarConverter::convert_from_float(argv[1]);
        else if (arg.find_first_not_of("0123456789.-") > arg.length())
            ScalarConverter::convert_from_double(argv[1]);
        else
        {
            std::cout << "char : Impossible\n";
            std::cout << "int : Impossible\n";
            std::cout << "float : nanf\n";
            std::cout << "double : nan\n";
        }
    }
    else
        std::cout << "empty arg \n";
    return (0);
}