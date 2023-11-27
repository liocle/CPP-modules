#include "Zombie.hpp"

Zombie* newZombie(std::string Zombie_on_the_heap);
void    randomChump(std::string Zombie_on_the_stack);

int main (void) {

    Zombie      *Zombie_on_the_heap;

    std::cout << std::endl << "⌛️ Once upon a compile time, randomChump() spawned a stacky zombie 📚🧟..." << std::endl;
    randomChump("Zombie_on_the_stack");
    std::cout << "It was short lived, the scope of randomChump() determined its undead lifetime... cheers 😘" << std::endl;

    std::cout << std::endl << "⏳ But from the stack, an heappy instance rose from the ashes 🍒🧟..." << std::endl;
    Zombie_on_the_heap = newZombie("Zombie_on_the_heap");
    Zombie_on_the_heap->announce();

    std::cout << "☣️  Only a delete() can get rid of a Heappy zombie instance: delete(🧠💦)💣 " << std::endl;
    delete Zombie_on_the_heap;
    
    std::cout << std::endl;

    return (1);
} 

