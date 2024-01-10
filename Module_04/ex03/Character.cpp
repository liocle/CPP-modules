#include "Character.hpp"

Character::Character() : _name("'A character'") {
    bzero(_inventory, sizeof(AMateria*) * INVENTORY_SIZE);
    bzero(_unequipped_objects, sizeof(AMateria*) * UNEQUIPPED_OBJ_MAX);
    std::cout << " -- Character " << getName() << " - Constructor called, _inventory and _unequipped_objects initialized to NULL -- " << std::endl;
}

Character::~Character() {
    for (int i = 0, j = 0; j < UNEQUIPPED_OBJ_MAX; i++, j++)
    {
        delete _unequipped_objects[j];
        if (i < INVENTORY_SIZE)
            delete _inventory[i];
    }
    std::cout << " -- Character " << getName() << " - Destructor called, _inventory and _unequipped_objects deleted -- " << std::endl;
}

Character::Character(const Character &other) : _name(other._name) {
    bzero(_inventory, sizeof(AMateria*) * INVENTORY_SIZE);
    bzero(_unequipped_objects, sizeof(AMateria*) * UNEQUIPPED_OBJ_MAX);
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (i < INVENTORY_SIZE && other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
    }
    std::cout << " -- Character " << getName() << " - Copy constructor called, _inventory and _unequipped_objects initialized to NULL -- " << std::endl;
}


Character& Character::operator=(const Character &other){
    _name = other._name;
    bzero(_unequipped_objects, sizeof(AMateria*) * UNEQUIPPED_OBJ_MAX);
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (i < INVENTORY_SIZE)
            _inventory[i] = other._inventory[i]->clone();
    }
    std::cout << " -- Character " << getName() << " - Copy constructor called, _inventory and _unequipped_objects initialized to NULL -- " << std::endl;
    return *this;
}

const std::string & Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria* materia) {
    if (!materia)
        return ;
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (_inventory[i]) {
            _inventory[i] = materia;
            return;
        }
    }
    delete materia;
}

void Character::unequip(int idx) {
    if ((unsigned int) idx < INVENTORY_SIZE && _inventory[idx]){
        for (int i = 0; i < UNEQUIPPED_OBJ_MAX; i++) {
            if ( _unequipped_objects[i] == NULL ) {
                _unequipped_objects[i] = _inventory[idx] ;
                _inventory[idx] = NULL;
                return;
            }
        }
    }
}

void    Character::use(int idx, Character& target) {
    if ((unsigned int) idx < UNEQUIPPED_OBJ_MAX && _inventory[idx]) {
        _inventory[idx]->use(target);
        return ;
    }

}
