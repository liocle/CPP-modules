#include "Zombie.hpp"

Zombie* newZombie(std::string Zombie_on_the_heap);
void    randomChump(std::string Zombie_on_the_stack);

int main (void) {

    Zombie      *Zombie_on_the_heap;

    std::cout << std::endl << "Once upon a compile time, randomChump() spawned a stacky zombie" << std::endl;
    randomChump("Zombie_on_the_stack");

    std::cout << std::endl << "But then, on the heap, an heappy instance approached..." << std::endl;
    Zombie_on_the_heap = newZombie("Zombie_on_the_heap");
    Zombie_on_the_heap->announce();

    std::cout << "Heappy zombies arent destroyed without a delete()" << std::endl;
    delete Zombie_on_the_heap;

    return (1);
} 

