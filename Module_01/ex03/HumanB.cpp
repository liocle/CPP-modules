
#include "HumanB.hpp"

HumanB::HumanB (std::string name) : _name(name), _weapon(NULL){}

HumanB::~HumanB (void) {}

void    HumanB::attack(void) {
    if (_weapon != NULL)
        std::cout << this->_name + " attacks with their " + this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name + " is unarmed" << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon_name) {
    this->_weapon = &weapon_name;
}

