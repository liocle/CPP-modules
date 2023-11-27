#include "Zombie.hpp"

Zombie* newZombie( std::string zombie_on_the_heap) {
    Zombie *pointer_to_zombie_instance;
    pointer_to_zombie_instance = new Zombie(zombie_on_the_heap);
    return pointer_to_zombie_instance;
}

