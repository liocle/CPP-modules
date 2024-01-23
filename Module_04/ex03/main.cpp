#include "IMateriaSource.hpp" 
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Color.hpp"

int main() {
    // {
    //     std::cout << std::endl;
    //     std::cout << CYAN << "--- example test ----------------------------------------------------------------------" << RESET << std::endl;

    //     std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "IMateriaSource* src = new MateriaSource();" << RESET << std::endl;
    //     IMateriaSource* src = new MateriaSource();
    //     std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "src->learnMateria(new Ice())" << RESET << std::endl;
    //     src->learnMateria(new Ice());

    //     std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "src->learnMateria(new Cure())" << RESET << std::endl;
    //     src->learnMateria(new Cure());

    //     std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "src->learnMateria(new Ice())" << RESET << std::endl;
    //     src->learnMateria(new Ice());


    //     std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "ICharacter* me = new Character(\"me\");" << RESET << std::endl;
    //     ICharacter* me = new Character("me");


    //     std::cout << std::endl;
    //     std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "AMateria* tmp;" << RESET << std::endl;
    //     AMateria* tmp;
    //     std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "tmp = src->createMateria(\"ice\");" << RESET << std::endl;
    //     tmp = src->createMateria("ice");
    //     std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "me->equip(tmp)" << RESET << std::endl;
    //     me->equip(tmp);
    //     std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "tmp = src->createMateria(\"cure\");" << RESET << std::endl;
    //     tmp = src->createMateria("cure");
    //     std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "me->equip(tmp)" << RESET << std::endl;
    //     me->equip(tmp);
    //     std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "tmp = src->createMateria(\"ice\");" << RESET << std::endl;
    //     tmp = src->createMateria("ice");
    //     std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "me->equip(tmp)" << RESET << std::endl;
    //     me->equip(tmp);


    //     std::cout << std::endl;
    //     std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "ICharacter* bob = new Character(\"bob\")" << RESET << std::endl;
    //     ICharacter* bob = new Character("bob");
    //     std::cout << CYAN << "--- Use Materia -------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "me->use(0, *bob)" << RESET << std::endl;
    //     me->use(0, *bob);
    //     std::cout << CYAN << "---- Use Materia ----------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "me->use(1, *bob)" << RESET << std::endl;
    //     me->use(1, *bob);
    //     std::cout << CYAN << "---- Use Materia ----------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "me->use(2, *bob)" << RESET << std::endl;
    //     me->use(2, *bob);
    //     std::cout << CYAN << "---- Use twice the same Materia -----------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "me->use(2, *bob)" << RESET << std::endl;
    //     me->use(2, *bob);
    //     std::cout << CYAN << "---- unequip last Materia -----------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "me->unequip(2)" << RESET << std::endl;
    //     me->unequip(2);
    //     std::cout << CYAN << "---- Use an unequipped Materia ----------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "me->use(2, *bob)" << RESET << std::endl;
    //     me->use(2, *bob);



    //     std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "delete bob" << RESET << std::endl;
    //     delete bob;
    //     std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "delete me" << RESET << std::endl;
    //     delete me;
    //     std::cout << CYAN << "----------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "delete src" << RESET << std::endl;
    //     delete src;
    // }
    // {
    //     std::cout << std::endl;
    //     std::cout << CYAN << "--- copy test ----------------------------------------------------------------------" << RESET << std::endl;

    //     std::cout << std::endl;
    //     std::cout << CYAN << "---- New MateriaSource  ----------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "IMateriaSource* src = new MateriaSource()" << RESET << std::endl;
    //     IMateriaSource* src = new MateriaSource();
    //     std::cout << std::endl;
    //     std::cout << CYAN << "---- learn Ice then Cure Materia ----------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "src->learnMateria(new Ice())" << RESET << std::endl;
    //     src->learnMateria(new Ice());
    //     src->learnMateria(new Cure());

    //     std::cout << std::endl;
    //     std::cout << CYAN << "---- Instantiate a *src_copy from MateriaSource ----------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "src_copy->learnMateria(new Ice())" << RESET << std::endl;
    //     IMateriaSource* src_copy = new MateriaSource(dynamic_cast<MateriaSource&>(*src));

    //     std::cout << std::endl;
    //     std::cout << std::endl;
    //     std::cout << CYAN << "--- new Character original -----------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "ICharacter* bob = new Character(\"original\")" << RESET << std::endl;
    //     ICharacter* original = new Character("original");

    //     std::cout << CYAN << "--- Original equips ice -----------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "original->equip(src_copy->createMateria(\"ice\"))" << RESET << std::endl;
    //     original->equip(src_copy->createMateria("ice"));
    //     std::cout << CYAN << "--- Original equips cure -----------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "original->equip(src_copy->createMateria(\"cure\"))" << RESET << std::endl;
    //     original->equip(src_copy->createMateria("cure"));

    //     std::cout << std::endl;
    //     std::cout << CYAN << "--- Original uses ice -----------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "original->use(0, *original)" << RESET << std::endl;
    //     original->use(0, *original);
    //     std::cout << CYAN << "--- Original uses cure -----------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "original->use(1, *original)" << RESET << std::endl;
    //     original->use(1, *original);

    //     std::cout << std::endl;
    //     std::cout << std::endl;
    //     std::cout << CYAN << "--- *original_char_is_copied Character is copied from *original -----------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "ICharacter* bob = new Character(\"original\")" << RESET << std::endl;
    //     ICharacter* copied_original_character = new Character(dynamic_cast<Character&>(*original));
    //     
    //     std::cout << std::endl;
    //     std::cout << CYAN << "--- *copied_original_character uses his _inventory, inherited from *original -----------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "copied_original_character->use({0,1}, *copied_original_character)" << RESET << std::endl;
    //     copied_original_character->use(0, *copied_original_character);
    //     copied_original_character->use(1, *copied_original_character);

    //     std::cout << std::endl;
    //     std::cout << CYAN << "---- Cleaning up ------------------------------------" << RESET << std::endl;
    //     std::cout << CYAN << "---- delete src Materia" << RESET << std::endl;
    //     delete src;
    //     std::cout << CYAN << "---- delete src_copy Materia" << RESET << std::endl;
    //     delete src_copy;
    //     std::cout << std::endl;
    //     std::cout << CYAN << "---- delete original character" << RESET << std::endl;
    //     delete original;
    //     std::cout << CYAN << "---- delete copied_original_character character" << RESET << std::endl;
    //     delete copied_original_character;
    // }
    {
        std::cout << std::endl;
        std::cout << CYAN << "--- overfill Character inventory test ---------------------------------------------------------------------" << RESET << std::endl;

        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");

        me->equip(src->createMateria("ice"));
        me->equip(src->createMateria("ice"));
        me->equip(src->createMateria("ice"));
        me->equip(src->createMateria("ice"));
        me->equip(src->createMateria("cure"));

        me->use(0, *me);
        me->use(1, *me);
        me->use(2, *me);
        me->use(3, *me);

        me->unequip(2);
        me->equip(src->createMateria("cure"));

        me->use(0, *me);
        me->use(1, *me);
        me->use(2, *me);
        me->use(3, *me);

        delete src;
        delete me;
    }
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

