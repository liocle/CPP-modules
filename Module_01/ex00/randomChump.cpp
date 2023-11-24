
#include "Zombie.hpp"

void    randomChump( std::string zombie_on_the_stack) {
    Zombie stack_zombie_instance(zombie_on_the_stack);
    stack_zombie_instance.announce();
}

