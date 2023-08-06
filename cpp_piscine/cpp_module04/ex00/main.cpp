#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wrong = new WrongCat();
    std::cout << i->get_Type() << " " << std::endl;
    std::cout << j->get_Type() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    wrong->makeSound();
    delete(meta);
    delete(i);
    delete(j);
    delete(wrong);
    return 0;
}