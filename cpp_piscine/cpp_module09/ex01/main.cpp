#include "RPN.hpp"

int main(int argc,char **argv)
{
    if (argc != 2)
    {
        std::cout << "Wrong number of argument\n";
        return (1);
    }
    std::string arg = argv[1];
    if (arg.empty() == true)
    {
        std::cout << "Error empty arg\n";
        return (1);
    }
    RPN::calculation(argv[1]);
    return (0);
}