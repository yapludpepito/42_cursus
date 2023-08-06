#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

int main()
{

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    Animal *tab[10];

    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            tab[i] = new Cat();
        else
            tab[i] = new Dog();
    }

    for (int i = 0; i < 10; i++)
        delete tab[i];

    delete j;//should not create a leak
    delete i;

return (0);
}
