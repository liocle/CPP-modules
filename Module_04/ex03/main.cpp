#include "IMateriaSource.hpp" 
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Color.hpp"

int main() {
    {
        std::cout << std::endl;
        std::cout << CYAN << "--- example test ----------------------------------------------------------------------" << RESET << std::endl;

        std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
        std::cout << CYAN << "IMateriaSource* src = new MateriaSource();" << RESET << std::endl;
        IMateriaSource* src = new MateriaSource();
        std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
        std::cout << CYAN << "src->learnMateria(new Ice())" << RESET << std::endl;
        src->learnMateria(new Ice());

        std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
        std::cout << CYAN << "src->learnMateria(new Cure())" << RESET << std::endl;
        src->learnMateria(new Cure());

        std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
        std::cout << CYAN << "ICharacter* me = new Character(\"me\");" << RESET << std::endl;
        ICharacter* me = new Character("me");


        std::cout << std::endl;
        std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
        std::cout << CYAN << "AMateria* tmp;" << RESET << std::endl;
        AMateria* tmp;
        std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
        std::cout << CYAN << "tmp = src->createMateria(\"ice\");" << RESET << std::endl;
        tmp = src->createMateria("ice");
        std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
        std::cout << CYAN << "me->equip(tmp)" << RESET << std::endl;
        me->equip(tmp);
        std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
        std::cout << CYAN << "tmp = src->createMateria(\"cure\");" << RESET << std::endl;
        tmp = src->createMateria("cure");
        std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
        std::cout << CYAN << "me->equip(tmp)" << RESET << std::endl;
        me->equip(tmp);


        std::cout << std::endl;
        std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
        std::cout << CYAN << "ICharacter* bob = new Character(\"bob\")" << RESET << std::endl;
        ICharacter* bob = new Character("bob");
        std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
        std::cout << CYAN << "me->use(0, *bob)" << RESET << std::endl;
        me->use(0, *bob);
        std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
        std::cout << CYAN << "me->use(1, *bob)" << RESET << std::endl;
        me->use(1, *bob);

        std::cout << std::endl;
        std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
        std::cout << CYAN << "delete bob" << RESET << std::endl;
        delete bob;
        std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
        std::cout << CYAN << "delete me" << RESET << std::endl;
        delete me;
        std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
        std::cout << CYAN << "delete src" << RESET << std::endl;
        delete src;
    }
//     {
//         std::cout << std::endl;
//         std::cout << CYAN << "--- copy test ----------------------------------------------------------------------" << RESET << std::endl;

//         IMateriaSource* src = new MateriaSource();
//         src->learnMateria(new Ice());
//         src->learnMateria(new Cure());
//         std::cout << RED << "HERE" << RESET << std::endl;
//         IMateriaSource* src_copy = new MateriaSource(dynamic_cast<MateriaSource&>(*src));

//         ICharacter* orig = new Character("orig");
//         orig->equip(src_copy->createMateria("ice"));
//         orig->equip(src_copy->createMateria("cure"));
//         orig->use(0, *orig);
//         orig->use(1, *orig);

//         ICharacter* copy = new Character(dynamic_cast<Character&>(*orig));
//         copy->use(0, *copy);
//         copy->use(1, *copy);

//         delete src;
//         delete src_copy;
//         delete orig;
//         delete copy;
//     }
//     {
//         std::cout << std::endl;
//         std::cout << CYAN << "--- overfill Character inventory test ---------------------------------------------------------------------" << RESET << std::endl;

//         IMateriaSource* src = new MateriaSource();
//         src->learnMateria(new Ice());
//         src->learnMateria(new Cure());

//         ICharacter* me = new Character("me");

//         me->equip(src->createMateria("ice"));
//         me->equip(src->createMateria("ice"));
//         me->equip(src->createMateria("ice"));
//         me->equip(src->createMateria("ice"));
//         me->equip(src->createMateria("cure"));

//         me->use(0, *me);
//         me->use(1, *me);
//         me->use(2, *me);
//         me->use(3, *me);

//         me->unequip(2);
//         me->equip(src->createMateria("cure"));

//         me->use(0, *me);
//         me->use(1, *me);
//         me->use(2, *me);
//         me->use(3, *me);

//         delete src;
//         delete me;
//     }
//     {
//         std::cout << std::endl;
//         std::cout << CYAN << "--- overfill MateriaSource inventory test ----------------------------------------------------------------------" << RESET << std::endl;

//         IMateriaSource* src = new MateriaSource();
//         src->learnMateria(new Ice());
//         src->learnMateria(new Ice());
//         src->learnMateria(new Ice());
//         src->learnMateria(new Ice());
//         src->learnMateria(new Cure());

//         delete src;
//     }
//     {
//         std::cout << std::endl;
//         std::cout << CYAN << "--- overfill Character pile test ----------------------------------------------------------------------" << RESET << std::endl;

//         IMateriaSource* src = new MateriaSource();
//         src->learnMateria(new Ice());
//         src->learnMateria(new Cure());

//         ICharacter* me = new Character("me");

//         // fill the pile, inventory empty
//         for (int i = 0; i < 100; i++) {
//             me->equip(src->createMateria("ice"));
//             me->unequip(0);
//         }

//         // fill the inventory as well
//         for (int i = 0; i < 4; i++) {
//             me->equip(src->createMateria("ice"));
//         }

//         // unequip slot 1 and equip cure
//         // should not unequip because pile full, should not equip because inventory full
//         me->unequip(1);
//         me->equip(src->createMateria("cure"));

//         // check that slot 1 is still ice, not cure
//         me->use(1, *me);

//         delete src;
//         delete me;
//     }
//     return 0;
}

