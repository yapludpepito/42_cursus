#include "Span.hpp"

int main(void)
{
    span a(22);
    int myarray [22] = {};
    srand(clock());
    for (unsigned int i = 0; i < 22; i++)
        myarray[i] = (rand() % 365);
    try
    {
       a.shortestSpan();
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }

    try
    {
        a.addManyNumbers(myarray, 22);
        std::cout << a.longestSpan() << std::endl;
        std::cout << a.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }

    try 
    {
        a.addNumber(0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }

    try 
    {
        std::cout << a.shortestSpan() << std::endl;
        std::cout << a.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}