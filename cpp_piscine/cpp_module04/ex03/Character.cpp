#include "Character.hpp"

Character::Character()
{
    this->Name = "Default";
    this->inventaire[0] = NULL;
    this->inventaire[1] = NULL;
    this->inventaire[2] = NULL;
    this->inventaire[3] = NULL;
}

Character::Character(const Character &mister)
{
    this->Name = mister.Name;
    this->inventaire[0] = NULL;
    this->inventaire[1] = NULL;
    this->inventaire[2] = NULL;
    this->inventaire[3] = NULL;
    for (int i = 0; i < 4; i++)
    {
        if (mister.inventaire[i] != NULL)
            this->inventaire[i] = mister.inventaire[i]->clone();
        else
            this->inventaire[i] = NULL;
    }
}

Character::Character(std::string const &name)
{
    this->Name = name;
    this->inventaire[0] = NULL;
    this->inventaire[1] = NULL;
    this->inventaire[2] = NULL;
    this->inventaire[3] = NULL;
}

Character::~Character() 
{
    for (int i = 0; i < 4; i++)
        if (this->inventaire[i])
            delete inventaire[i];
}

std::string const &Character::getName() const
{
    return (this->Name);
}

void Character::equip(AMateria* m)
{
    if (m == 0)
        return ;
    if (inventaire[0] == NULL)
        inventaire[0] = m;
    else if (inventaire[1] == NULL)
        inventaire[1] = m;
    else if (inventaire[2] == NULL)
        inventaire[2] = m;
    else if (inventaire[3] == NULL)
        inventaire[3] = m;
    else
        std::cout << "no empty slot in ur inventory\n";
}

void Character::unequip(int idx)
{
    if (idx < 4 && idx >= 0)
        this->inventaire[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
        return ;
    if (inventaire[idx])
        this->inventaire[idx]->use(target);
    else
        std::cout << "not any item at index : " << idx << "\n";
}

Character &Character::operator=(const Character &Charac)
{
    if (this != &Charac)
    {
        this->Name = Charac.getName();
        for (int i = 0; i < 4; i++)
        {
            if (this->inventaire[i] != NULL)
                delete (this->inventaire[i]);
            if (Charac.inventaire[i])
                this->inventaire[i] = Charac.inventaire[i]->clone();
            else
                this->inventaire[i] = NULL;
        }
    }
    return (*this);
}
