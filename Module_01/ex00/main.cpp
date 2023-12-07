#include "Zombie.hpp"

Zombie* newZombie(std::string zombie_on_the_heap);
void    randomChump(std::string zombie_on_the_stack);

int main (void) {

    Zombie      *zombie_on_the_heap;

    std::cout << std::endl << "⌛️ Once upon a compile time, randomChump() spawned a stacky zombie 📚🧟..." << std::endl;
    randomChump("zombie_on_the_stack");
    std::cout << "It was short lived, the scope of randomChump() determined its undead lifetime... cheers 😘" << std::endl;

    std::cout << std::endl << "⏳ But from the stack, a new() heappy instance rose from the pointed ashes 👼🧟..." << std::endl;
    zombie_on_the_heap = newZombie("zombie_on_the_heap");
    zombie_on_the_heap->announce();

    std::cout << "☣️  Only a delete(💣) can prevent a Heappy zombie instance to leak all over 🧠💦: " << std::endl;
    delete zombie_on_the_heap;
    
    std::cout << std::endl;

    return (1);
} 

