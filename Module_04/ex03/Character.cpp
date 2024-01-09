#include "Character.hpp"

Character::Character() : _name("A character") {
    std::cout << " - Character - Constructor - " << std::endl;
}

Character::~Character() {
    std::cout << " - Character - Destructor - " << std::endl;
    for (AMateria *m : _inventory)
    {
        delete m;
    }
}

Character::Character(const Character &other) : _name(other._name)
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {

    }

}

