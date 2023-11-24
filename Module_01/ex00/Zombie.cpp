#include "Zombie.hpp"


Zombie::Zombie (std::string zombie_name) : _name(zombie_name) {
}

Zombie::~Zombie(void) {
    std::cout << this->_name << " goes back to where it belongs." << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->_name <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}  
