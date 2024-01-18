#include "Color.hpp"
#include "Character.hpp"

Character::Character() : _name("'A character'") {
    bzero(_inventory, sizeof(AMateria*) * INVENTORY_SIZE);
    bzero(_unequipped_objects, sizeof(AMateria*) * UNEQUIPPED_OBJ_MAX);
    std::cout << MAGENTA << " **** Character " << getName() << " - Constructor called, _inventory and _unequipped_objects initialized to nullptr **** " << RESET << RESET << std::endl;
}

Character::Character(std::string const &name) : _name(name) {
    bzero(_inventory, sizeof(AMateria*) * INVENTORY_SIZE);
    bzero(_unequipped_objects, sizeof(AMateria*) * UNEQUIPPED_OBJ_MAX);
    std::cout << MAGENTA << " **** Character " << getName() << " - Constructor called, _inventory and _unequipped_objects initialized to nullptr **** " << RESET << std::endl;
}


Character::~Character() {
    for (int i = 0, j = 0; j < UNEQUIPPED_OBJ_MAX; i++, j++)
    {
        if (_unequipped_objects[j] != nullptr)
            delete _unequipped_objects[j];
        if (i < INVENTORY_SIZE && _inventory[i] != nullptr)
            delete _inventory[i];
    }
    std::cout << MAGENTA << " **** Character " << getName() << " - Destructor called, _inventory and _unequipped_objects deleted **** " << RESET << std::endl;
}

Character::Character(const Character &other) : _name(other._name) {
    bzero(_inventory, sizeof(AMateria*) * INVENTORY_SIZE);
    bzero(_unequipped_objects, sizeof(AMateria*) * UNEQUIPPED_OBJ_MAX);
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (i < INVENTORY_SIZE && other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
    }
    std::cout << MAGENTA << " **** Character " << getName() << " - Copy constructor called, _inventory and _unequipped_objects initialized to nullptr **** " << RESET << std::endl;
}


Character& Character::operator=(const Character &other){
    _name = other._name;
    bzero(_unequipped_objects, sizeof(AMateria*) * UNEQUIPPED_OBJ_MAX);
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (i < INVENTORY_SIZE)
            _inventory[i] = other._inventory[i]->clone();
    }
    std::cout << MAGENTA << " **** Character " << getName() << " - Copy assignment operator called, _inventory and _unequipped_objects initialized to nullptr **** " << RESET << std::endl;
    return *this;
}

const std::string & Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria* materia) {
    if (materia != nullptr) {
        for (int i = 0; i < INVENTORY_SIZE; i++)
        {
            if (_inventory[i]) {
                _inventory[i] = materia;
                return;
            }
        }
        delete materia;
    }
}

void Character::unequip(int idx) {
    if ((unsigned int) idx < INVENTORY_SIZE && _inventory[idx]){
        for (int i = 0; i < UNEQUIPPED_OBJ_MAX; i++) {
            if ( _unequipped_objects[i] == nullptr ) {
                _unequipped_objects[i] = _inventory[idx] ;
                _inventory[idx] = nullptr;
                return;
            }
        }
    }
    else 
        std::cout << MAGENTA << "Cannot unequip this Materia" << RESET << std::endl;
}

void    Character::use(int idx, ICharacter& target) {
    
    if (idx < 0 || idx >= UNEQUIPPED_OBJ_MAX || _inventory[idx] == nullptr) {
        std::cout << RED << "HERE IN CHARACTER use() " << RESET << std::endl;
        return ;
    }
    _inventory[idx]->use(target);

}
