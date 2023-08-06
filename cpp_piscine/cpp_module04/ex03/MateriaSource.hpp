#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
    AMateria *a[4];

    public:
        ~MateriaSource();
        MateriaSource();
        MateriaSource(const MateriaSource &ref);
		MateriaSource &operator=(const MateriaSource &ref);
        void learnMateria(AMateria* M);
        AMateria* createMateria(std::string const & type);
};




#endif