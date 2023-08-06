#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"


// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     Character* me = new Character("me");
//     AMateria* tmp;
//     AMateria* tmp2;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp2 = src->createMateria("cure");
//     me->equip(tmp2);
//     Character* bob = new Character("bob");
//     *bob = *me;
//     me->use(0, *bob);   
//     me->use(1, *bob);
//     me->unequip(1);
//     me->unequip(0);
//     delete bob;
//     delete me;
//     delete src;
//     delete tmp;
//     delete tmp2;
//     return 0;
// }


int main(void)
{
	std::cout << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	std::cout << std::endl;

	AMateria	*tmp;
	AMateria	*tmp1;
	AMateria	*tmp2;
	AMateria	*tmp3;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp1 = src->createMateria("cure");
	me->equip(tmp1);

	tmp = src->createMateria("fire");
	me->equip(tmp);
	std::cout << std::endl;

	
	Character	*nick = new Character("Nick");
	tmp2 = src->createMateria("cure");
	nick->equip(tmp2);
	tmp3 = src->createMateria("ice");
	nick->equip(tmp3);
	
	tmp = src->createMateria("earth");
	nick->equip(tmp);

	Character	*nick_copy = new Character(*nick);
	std::cout << std::endl;

	std::cout << "TEST USE\n\n";
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	me->use(-4, *bob);
	me->use(18, *bob);
	
	tmp = src->createMateria("cure");
	nick_copy->equip(tmp);
	tmp = src->createMateria("ice");
	nick_copy->equip(tmp);
	
	std::cout << "NICK USE : " << std::endl;
	
	nick->use(0, *bob);
	nick->use(1, *bob);
	nick->use(2, *bob);
	nick->use(3, *bob);
	
	std::cout << "NICK COPY USE : " << std::endl;
	nick_copy->use(0, *bob);
	nick_copy->use(1, *bob);
	nick_copy->use(2, *bob);
	nick_copy->use(3, *bob);
	std::cout << std::endl;

	std::cout << "UNEQUIP:\n\n";
	nick->unequip(0);

	me->unequip(-1);
	me->unequip(18);
	me->unequip(3);
	std::cout << std::endl;
	me->use(1, *nick);
	me->unequip(1); // this materia's adress is save in tmp 1
	me->use(1, *nick);
	std::cout << std::endl;

	delete tmp1;
	delete tmp2;
	
	delete bob;
	delete me;
	delete src;
	delete nick;
	delete nick_copy;
	std::cout << std::endl;
	return(0);
}