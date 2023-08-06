#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

//dynamic cast

Base * generate(void)
{
    int random_variable = std::rand();

    if (random_variable % 3 == 0)
        return (new A());
    else if (random_variable % 3 == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "it's an A class\n" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "it's an B class\n" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "it's an C class\n" << std::endl;
}

void identify(Base& p)
{
    try 
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "it's an A class\n" << std::endl;
        (void)a;
    }
    catch (std::exception &exep)
    {
        (void)exep;
    }

    try 
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << "it's an B class\n" << std::endl;
        (void)b;
    }
    catch (std::exception &exep)
    {
        (void)exep;
    }
    
    try 
    {
        C &c = dynamic_cast<C&>(p);
        std::cout << "it's an C class\n" << std::endl;
        (void)c;
    }
    catch (std::exception &exep)
    {
        (void)exep;
    }
}

int main(void)
{
    std::srand(std::clock());

    Base *base = generate();
    Base *base2 = generate();

    identify(base);
    identify(*base2);

    delete base;
    delete base2;
    
    return (0);
}