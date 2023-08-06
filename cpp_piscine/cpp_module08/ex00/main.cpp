#include "easyfind.hpp"
#include <vector>
#include <list>
#include <exception>


int main()
{
    std::vector<int> a;

    a.push_back(2);
    try
    {
            std::cout << *easyfind(a, 5) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    a.push_back(5);
    try 
    {
        std::cout << *easyfind(a, 5) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }

}