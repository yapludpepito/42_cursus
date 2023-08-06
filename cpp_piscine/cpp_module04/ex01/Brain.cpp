#include "Brain.hpp"

Brain::Brain()
{std::cout << "Brain created\n";}

Brain::~Brain()
{std::cout << "Brain destroyed\n";}

Brain::Brain(const Brain &other)
{
    for (int i = 0; i< 100; i++)
        this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &) {return *this;}
