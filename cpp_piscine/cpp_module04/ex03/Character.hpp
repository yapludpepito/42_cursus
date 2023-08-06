#ifndef CHARACTER_HPP
#define CHARACTER_HPP


#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class Character : public ICharacter
{
    private :
        AMateria    *inventaire[4];
        std::string Name;

    public :
        ~Character();
        std::string const &getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
		Character &operator=(const Character &);
		Character(const Character &mister);
        Character();
        Character(std::string const &name);
};




#endif