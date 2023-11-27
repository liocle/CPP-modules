#include "Zombie.hpp"

Zombie::Zombie () : _name("Zombie cloned to default") {}

Zombie::Zombie (std::string zombie_name) : _name(zombie_name) {}

Zombie::~Zombie(void) {
    std::cout << "\t🧟 " + this->_name + " goes back to where it belongs... 🧨🔥" << std::endl;
}

void Zombie::announce( int horde_size ) {
    std::cout << "\t🧠 " + this->_name << " #" << horde_size << "✌️ : BraiiiiiiinnnzzzZ🥤..." << std::endl;
}  

void Zombie::name_this_zombie( std::string name_them ) {
   this->_name = name_them; 

}

