#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
    this->a[0] = NULL;
    this->a[1] = NULL;
    this->a[2] = NULL;
    this->a[3] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &ref)
{
    this->a[0] = NULL;
    this->a[1] = NULL;
    this->a[2] = NULL;
    this->a[3] = NULL;
    *this = ref;
}


MateriaSource &MateriaSource::operator=(const MateriaSource &ref)
{
    if (this != &ref)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->a[i] != NULL)
                delete (this->a[i]);
            if (ref.a[i])
                this->a[i] = ref.a[i]->clone();
            else
                this->a[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    if (a[0] != NULL)
        delete (this->a[0]);
    if (a[1] != NULL)
        delete (this->a[1]);
    if (a[2] != NULL)
        delete (this->a[2]);
    if (a[3] != NULL)
        delete (this->a[3]);
}

void MateriaSource::learnMateria(AMateria* M)
{
    if (a[0] == NULL)
        a[0] = M;
    else if (a[1] == NULL)
        a[1] = M;
    else if (a[2] == NULL)
        a[2] = M;
    else if (a[3] == NULL)
        a[3] = M;
    else
        std::cout << "no empty slot in ur inventory\n";
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
        if (a[i])
            if (a[i]->get_Type() == type)
                return (a[i]->clone()); 
    return (0);
}